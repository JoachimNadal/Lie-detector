# STM32 ECG Acquisition Firmware

## Hardware
- STM32 Nucleo-F446ZE
- ECG analog frontend custom
- ADC input: PA0

## Features
- ADC1 acquisition
- DMA circular mode
- TIM2 trigger
- UART streaming
- 500 Hz sampling

## STM32CubeMX Configuration

### ADC1
- Channel: IN0 (PA0)
- Resolution: 12-bit
- DMA Circular
- External Trigger: TIM2 TRGO

### TIM2
- Update frequency: 500 Hz
- TRGO on update event

### USART2
- 115200 baud

## Expected ADC Values

### VREF = 2.5V
Expected idle ADC value:
~3100

### VREF = 1.65V
Expected idle ADC value:
~2048

## UART Output Format

Raw ADC values:
3101
3098
3105
...

## TODO
- Digital notch filter
- BPM extraction
- ECG peak detection
- Bluetooth streaming
