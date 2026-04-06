This folder contains all Section A simulations.

# Q1 – Blinking LEDs using millis()

## Circuit
![Circuit](Q1-circuit.png)

## Explanation
This circuit uses the millis() function to blink three LEDs at different intervals simultaneously. Each LED has an independent timer that checks elapsed time and toggles the LED when its interval is reached. This non-blocking approach allows multiple LEDs to run at the same time.
