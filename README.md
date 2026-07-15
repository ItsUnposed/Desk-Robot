# Desk-Robot

A small desk robot that reacts to its surroundings and shows an animated face on a display. This repository holds the code, hardware notes, and future modules for the project.

## Status

The project currently contains one finished piece: an OLED display that shows two animated eyes. The animations run purely on fixed timers — there are no sensors and no randomness yet.

## Table of Contents

- [Current Feature: OLED Eyes](#current-feature-oled-eyes)
- [Hardware](#hardware)
- [Getting Started](#getting-started)
- [Roadmap](#roadmap)
- [License](#license)

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

## Getting Started

> This section is a placeholder. 


## Roadmap

- [ ] Add sensors (proximity, sound, etc.) so the robot can react to its environment.
- [ ] Add motors, if the robot should move or turn its head.
- [ ] Design an enclosure/housing.
- [ ] Rewrite animations to be non-blocking (`millis()`-based instead of `delay()`-based) once other tasks need to run at the same time as the animations.
