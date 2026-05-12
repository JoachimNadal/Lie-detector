import serial
import csv
import time
from collections import deque

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


SERIAL_PORT = "COM3"      # Windows example
# SERIAL_PORT = "/dev/ttyACM0"  # Linux example
BAUDRATE = 115200

MAX_POINTS = 1000
CSV_FILE = "ecg_recording.csv"


raw_data = deque(maxlen=MAX_POINTS)
filtered_data = deque(maxlen=MAX_POINTS)
time_data = deque(maxlen=MAX_POINTS)

start_time = time.time()

ser = serial.Serial(SERIAL_PORT, BAUDRATE, timeout=1)

csv_file = open(CSV_FILE, "w", newline="")
csv_writer = csv.writer(csv_file)
csv_writer.writerow(["time_s", "raw_adc", "filtered_voltage"])


fig, ax = plt.subplots()
line, = ax.plot([], [])

ax.set_title("Real-time ECG Signal")
ax.set_xlabel("Time (s)")
ax.set_ylabel("Filtered voltage (V)")
ax.grid(True)


def update(frame):
    while ser.in_waiting:
        try:
            line_bytes = ser.readline()
            line_str = line_bytes.decode("utf-8").strip()

            if not line_str:
                continue

            raw_str, filtered_str = line_str.split(",")

            raw = int(raw_str)
            filtered = float(filtered_str)
            t = time.time() - start_time

            raw_data.append(raw)
            filtered_data.append(filtered)
            time_data.append(t)

            csv_writer.writerow([t, raw, filtered])

        except Exception:
            pass

    if len(time_data) > 2:
        line.set_data(time_data, filtered_data)
        ax.set_xlim(max(0, time_data[0]), time_data[-1])
        ax.set_ylim(min(filtered_data) - 0.1, max(filtered_data) + 0.1)

    return line,


ani = FuncAnimation(fig, update, interval=20)
plt.show()

csv_file.close()
ser.close()
