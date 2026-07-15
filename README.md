# Desk-Robot

A small desk robot that reacts to its surroundings and shows an animated face on a display. This repository holds the code, hardware notes, and future modules for the project.

## Status

The project currently contains one finished piece: an OLED display that shows two animated eyes. The animations run purely on fixed timers — there are no sensors and no randomness yet.

## Table of Contents

- [Current Feature: OLED Eyes](#current-feature-oled-eyes)
- [Hardware](#hardware)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Roadmap](#roadmap)

## Current Feature: OLED Eyes

Two rounded rectangles represent the robot's eyes. Each animation triggers on its own fixed time interval.

| Animation    | Trigger                       | Description                              |
|--------------|--------------------------------|-------------------------------------------|
| `normal`     | On startup                     | Eyes resting, open                        |
| `blink`      | Every ~30 seconds               | Quick close and open                      |
| `watchLeft`  | Every ~10 minutes (offset)       | Eyes shift left and back                  |
| `watchRight` | Every ~10 minutes (offset)       | Eyes shift right and back                 |
| `observe`    | Every ~10 minutes (offset)       | Eyes sweep in a curve                     |
| `sleep`      | Every hour, exactly              | Eyes close, "Z" symbols appear            |
| `wakeUp`     | Automatically after `sleep`     | Eyes open again                           |

**Timing notes:**

- `watchLeft`, `watchRight`, and `observe` each start with a different offset when the device boots, so the three animations do not fire at the same moment.
- `sleep` has priority over every other animation. If a `sleep` cycle is due, no other animation is allowed to run at the same time, which keeps the animations from overlapping.

## Hardware

The current build uses the following components:

| Component        | Detail                                   |
|-------------------|-------------------------------------------|
| Microcontroller   | Arduino Nano ESP32                        |
| Display           | SH1107-based OLED, 128×128 pixels, I2C bus |

## Project Structure

```
Desk-Robot/
├── Desk-Robot-Code/           # PlatformIO project (CLion)
│   ├── platformio.ini         # Board/framework/library configuration
│   └── src/
│       ├── main.cpp           # Entry point (setup/loop)
│       └── OLED-Display/
│           ├── OLED-main/     # Setup and animation scheduler (chooseFace)
│           ├── OLED-faces/    # Individual eye animations
│           └── OLED-variables/# Shared timing constants and state
└── Pictures/                  # Concept art and build progress photos
```

## Getting Started

This is a [PlatformIO](https://platformio.org/) project, developed using the [CLion](https://www.jetbrains.com/clion/) PlatformIO plugin.

1. Clone the repository and open the `Desk-Robot-Code` folder as a PlatformIO project (in CLion, or with the [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation/index.html)/VS Code extension).
2. Connect the Arduino Nano ESP32 via USB.
3. Wire the SH1107 OLED display to the board's I2C pins (SDA/SCL).
4. Build and upload the `arduino_nano_esp32` environment defined in `platformio.ini`.
5. Open the serial monitor at 115200 baud to see setup/error messages.

## Roadmap

- [ ] Add sensors (proximity, sound, etc.) so the robot can react to its environment.
- [ ] Add motors, if the robot should move or turn its head.
- [ ] Design an enclosure/housing.
- [ ] Rewrite animations to be non-blocking (`millis()`-based instead of `delay()`-based) once other tasks need to run at the same time as the animations.
