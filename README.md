# Desk-Robot

A small desk robot that reacts to its surroundings and shows an animated face on a display. This repository holds the code, hardware notes, and future modules for the project.

## Status

The main piece so far: an OLED display showing two animated eyes, driven by `Desk-Robot-Code`. Most animations run on fixed timers, but the robot now reacts to one real sensor — a photoresistor decides when the eyes fall asleep and wake up based on the ambient light level.

Two parts of the project are still scaffolding without behavior yet:
- **Power module** (`src/Power`) — header/source files exist, no logic implemented.
- **`Deck-Code`** — a second, separate PlatformIO project for another physical component of the robot; currently an empty skeleton.

## Table of Contents

- [Current Feature: OLED Eyes](#current-feature-oled-eyes)
- [Hardware](#hardware)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Roadmap](#roadmap)

## Current Feature: OLED Eyes

Two rounded rectangles represent the robot's eyes.

| Animation    | Trigger                                              | Description                     |
|--------------|-------------------------------------------------------|----------------------------------|
| `normal`     | On startup                                             | Eyes resting, open               |
| `blink`      | Every ~30 seconds                                      | Quick close and open             |
| `watchLeft`  | Every ~5 minutes (offset)                              | Eyes shift left and back         |
| `watchRight` | Every ~5 minutes (offset)                              | Eyes shift right and back        |
| `observe`    | Every ~5 minutes (offset)                              | Eyes sweep in a curve            |
| `sleep`      | Photoresistor reading drops below ~500 (it's dark)     | Eyes close, "Z" symbols appear   |
| `wakeUp`     | While asleep, reading rises above ~1500 (it's bright)  | Eyes open again                  |

**Timing notes:**

- `watchLeft`, `watchRight`, and `observe` each start with a different offset when the device boots, so the three animations do not fire at the same moment.
- `sleep` has priority over every other animation. While the robot is asleep, no other animation runs — the main loop just polls the photoresistor until it's bright enough to `wakeUp`.

## Hardware

The current build uses the following components:

| Component        | Detail                                                     |
|-------------------|--------------------------------------------------------------|
| Microcontroller   | ESP32 dev board (`esp32dev` in PlatformIO)                   |
| Display           | SH1107-based OLED, 128×128 pixels, I2C bus                   |
| Light sensor      | Photoresistor (LDR) via voltage divider into an analog pin (GPIO32), used for the sleep/wake behavior |

## Project Structure

```
Desk-Robot/
├── Desk-Robot-Code/           # Main PlatformIO project (CLion) — the robot's "head"
│   ├── platformio.ini         # Board/framework/library configuration
│   └── src/
│       ├── main.cpp           # Entry point (setup/loop)
│       ├── OLED-Display/
│       │   ├── OLED-main/     # Setup and animation scheduler (chooseFace)
│       │   ├── OLED-faces/    # Individual eye animations
│       │   └── OLED-variables/# Shared timing constants and state
│       ├── Sensors/
│       │   └── Photoresistor/ # Ambient light reading, drives sleep/wake
│       └── Power/             # Power management (scaffolded, not yet implemented)
├── Deck-Code/                 # Second PlatformIO project, currently an empty skeleton
└── Pictures/                  # Concept art and build progress photos
```

## Getting Started

This is a [PlatformIO](https://platformio.org/) project, developed using the [CLion](https://www.jetbrains.com/clion/) PlatformIO plugin.

1. Clone the repository and open the `Desk-Robot-Code` folder as a PlatformIO project (in CLion, or with the [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation/index.html)/VS Code extension).
2. Connect the ESP32 board via USB.
3. Wire the SH1107 OLED display to the board's I2C pins (SDA/SCL).
4. Wire the photoresistor as a voltage divider into GPIO32.
5. Build and upload the `esp32dev` environment defined in `platformio.ini`.
6. Open the serial monitor at 115200 baud to see setup/error messages and live photoresistor readings.

## Roadmap

- [ ] Implement the `Power` module (battery monitoring / power management).
- [ ] Give `Deck-Code` actual functionality.
- [ ] Add more sensors (proximity, sound, etc.) so the robot can react to more of its environment.
- [ ] Add motors, if the robot should move or turn its head.
- [ ] Design an enclosure/housing.