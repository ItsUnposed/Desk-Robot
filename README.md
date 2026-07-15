# Desk-Robot

## About

This repository is the home for a small desk robot project. The end goal is a self-contained little device that sits on a desk, reacts to its surroundings and shows a face with animated eyes on a display. Everything for the robot — code, hardware notes, future modules — will live here as the project grows.

Right now, the repo contains the first working piece: an OLED display showing two animated eyes, driven purely by timing (no sensors or randomness yet).

## Current feature: OLED eyes

Two rounded rectangles act as "eyes" and run different animations on fixed time intervals:

| Animation    | Timing                                  | Description |
|--------------|------------------------------------------|--------------|
| `normal`     | on startup                                | Eyes resting, open |
| `blink`      | ~every 30 seconds                         | Quick close and open |
| `watchLeft`  | ~every 10 min (offset timing)             | Eyes shift left and back |
| `watchRight` | ~every 10 min (offset timing)             | Eyes shift right and back |
| `observe`    | ~every 10 min (offset timing)             | Eyes sweep in a curve |
| `sleep`      | exactly every hour                        | Eyes close, "Z" symbols appear |
| `wakeUp`     | automatically after `sleep`               | Eyes open again |

`watchLeft`, `watchRight`, and `observe` are staggered on startup so they don't fire at the same time. `sleep` takes priority over everything else so animations never overlap.

## Hardware

- Arduino Nano ESP32
- SH1107-based OLED display, 128x128, I2C

## Roadmap

- Sensors (proximity, sound, etc.) so the robot reacts to its environment
- Motors, if the robot should move or turn its head
- Enclosure/housing
- Possibly rewriting animations to be non-blocking (`millis()`-based instead of `delay()`) once other tasks need to run concurrently
