# ECG Lie Detector

## Overview

This project is an open-source ECG acquisition system built using:

* Analog electronics
* STM32 microcontrollers
* Custom signal filtering
* Digital signal processing

The goal is to design a fully custom ECG analog front-end and process the signal digitally on STM32.

> Disclaimer:
> This is NOT a medical device.
> This project is for educational and research purposes only.

---

# Features

* 3-electrode ECG acquisition
* Custom analog front-end
* Instrumentation amplifier
* Analog filtering
* Digital 50 Hz notch filter
* STM32 ADC acquisition
* Open-source hardware and firmware

---

# Signal Chain

```text
RA / LA / RL electrodes
→ Input protection
→ Instrumentation amplifier
→ High-pass filter
→ Gain stage
→ Low-pass filter
→ STM32 ADC
→ Digital filtering
```

---

# Hardware

## Main Components

* STM32
* TLV271IP operational amplifiers
* ECG electrodes
* Passive filters
* Battery power supply

Future versions may use:

* INA826
* AD620
* OPA2188

---

# Filters

## Analog Filters

### High-pass filter

Used to remove:

* DC offset
* baseline drift

Cutoff frequency:

```text
~0.5 Hz
```

### Low-pass filter

Used to remove:

* high-frequency noise
* muscle noise

Cutoff frequency:

```text
~40 Hz
```

---

# Digital Processing

Digital filtering is performed directly on the STM32.

## Implemented Filters

* 50 Hz notch filter
* Optional digital bandpass filter

---

# Safety

* Battery-powered only
* No direct connection to mains power
* Do NOT use while connected to a PC without isolation
* NOT medically certified

---

# Repository Structure

```text
ECG-Lie-Detector/
│
├── README.md
├── docs/
├── hardware/
├── firmware/
└── software/
```

---

# Hardware Folder

Contains:

* schematics
* BOM
* tests
* hardware documentation

---

# Firmware Folder

Contains STM32 code:

* ADC acquisition
* UART communication
* filtering
* DSP

---

# Software Folder

Contains:

* ECG viewer
* signal processing tools
* GUI applications
* future machine learning tools

---

# License

## Software / Firmware

MIT License

## Hardware

CERN-OHL-S v2

---

# Planned Features

* Real-time ECG display
* Bluetooth support
* OLED/LCD display
* 3D-printed enclosure
* Portable standalone device
* Signal recording
* Heart-rate extraction
* Improved filtering
* Machine learning analysis

---

# Future Hardware

Future versions of the project may include:

* LCD/OLED display
* Buttons and user controls
* Battery monitoring
* Portable enclosure
* Fully standalone operation
* 3D-printed case

The project is designed to evolve into a complete portable biosignal acquisition platform.

---

# Contributing

Contributions are welcome.

Possible contributions:

* analog electronics
* STM32 firmware
* DSP
* filtering
* documentation
* testing

---

# Author

Joachim Nadal
