# C-Play-Hands-Card-Game

![Language](https://img.shields.io/badge/language-C-blue)
![Build](https://img.shields.io/badge/build-GCC%2FClang-success)
![Topic](https://img.shields.io/badge/topic-arrays%20%7C%20functions%20%7C%20randomization-informational)
![Status](https://img.shields.io/badge/status-complete-brightgreen)
![License](https://img.shields.io/badge/license-MIT-yellow)

A C program that builds a standard 52-card deck, shuffles it using a Fisher–Yates shuffle, deals two 5-card hands, and determines a winner based on simple “play value” scoring (Ace=1, 2–9 face value, 10/J/Q/K=10). The program prints each card, totals each hand, and outputs a tie/winner result with a timestamp.

---

## Features
- Generates a full **52-card deck** (faces + suits)
- **Fisher–Yates shuffle** for unbiased randomization
- Deals **two hands of 5 cards**
- Computes and displays **hand totals**
- Declares **winner or tie**
- Prints **date/time stamp** for assignment screenshot requirements

---

## Files
- `main.c` — main implementation (deck init, shuffle, deal, scoring, output)
- `Code-1`, `Code-2` — screenshots of code (for submission documentation)
- `Output` — screenshot of console output

> Tip: If you want cleaner repo structure, rename `Code-1/Code-2/Output` to something like `screenshots/code_1.png`, `screenshots/code_2.png`, `screenshots/output.png`.

---

## How to Compile & Run

### macOS / Linux (GCC or Clang)
```bash
gcc -Wall -Wextra -O2 main.c -o play_hands
./play_hands
