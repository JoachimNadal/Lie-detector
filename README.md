# Lie Detector Biosignal System

Open-source biosignal acquisition and analysis platform based on:

- ECG (Electrocardiography)
- GSR (Galvanic Skin Response)
- Respiratory monitoring

The project combines custom analog electronics, embedded signal processing, STM32 firmware, desktop software, and 3D-printed hardware.

---

# Features

- Custom ECG analog front-end
- Galvanic Skin Response acquisition
- Respiratory signal monitoring
- STM32 real-time acquisition
- Digital filtering and DSP
- Real-time visualization software
- Portable standalone device
- 3D-printed enclosure
- Open-source hardware and firmware

---

# Biosignals

## ECG

3-electrode ECG acquisition system using:
- instrumentation amplifier
- Sallen-Key filters
- STM32 ADC acquisition

## GSR

Skin conductance measurement using:
- constant current excitation
- analog amplification
- low-noise filtering

## Respiration

Respiratory monitoring using:
- stretch sensor / belt sensor
- analog filtering
- breathing rate extraction

---

# Repository Structure

```text
hardware/   → analog electronics and enclosure
firmware/   → STM32 embedded code
software/   → desktop software and DSP
docs/       → documentation and theory
```

---

# Safety Disclaimer

This project is NOT a medical device.

For educational and research purposes only.

Never connect the device to mains-powered equipment without proper isolation.

---

# Planned Features

- OLED/LCD display
- Real-time waveform visualization
- Data recording
- Signal quality estimation
- Machine learning analysis
- Battery-powered standalone operation

---

# Hardware

- STM32 Nucleo
- TLV271IP operational amplifiers
- Analog filtering
- 3D-printed enclosure

---

# Software

- Real-time biosignal visualization
- DSP filtering
- Signal analysis
- Data logging
- Machine learning experiments

---

# Licenses

## Software / Firmware
MIT License

## Hardware
CERN-OHL-S v2

---

# Contributing

Contributions are welcome:
- analog electronics
- embedded systems
- DSP
- software
- mechanical design
- documentation

---

# Author

Joachim Nadal
