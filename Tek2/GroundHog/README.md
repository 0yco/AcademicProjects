# 🐿️ Groundhog - Extended Weather Forecast Tool (Data Analysis)

---

## 🚀 Overview

**Groundhog** is a command-line weather forecast analysis tool that processes real-time temperature data. It calculates technical indicators such as the temperature increase average (g), relative temperature evolution (r), and standard deviation (s) over a defined period, while also detecting trend switches and weather aberrations.

---

## 🔧 Setup Guide

### 📦 Compilation

- **Requirements**:
  - Python 3 installed
  - Make utility (optionnal, it was used to compile the project but used python3 is the same ^^)

- **Build the Binary**:
  Use the provided Makefile to compile the project:
  ```bash
  make
  ```

- **Cleanup Commands**:
  ```bash
  make clean      # Remove object files
  make fclean     # Remove binaries and object files
  ```

### 🏃 Running the Program

- **Execute** the program with a period (number of days):
  ```bash
  ./groundhog period
  ```
  For example, to set a 7-day period:
  ```bash
  ./groundhog 7
  ```

- **Display Help**:
  ```bash
  ./groundhog -h
  ```

---

## 🌟 Project Description

Groundhog reads temperature values from standard input and computes:
- **g**: The average increase in temperature (only counting positive differences) over the last *n* days.
- **r**: The relative temperature evolution between the most recent temperature and the temperature observed *n* days ago.
- **s**: The standard deviation of the temperatures over the last *n* days.

It also detects and alerts when a switch in global temperature tendency occurs. When the keyword `STOP` is encountered, the program outputs:
- The total number of detected trend switches.
- The five biggest aberrations (weirdest values) observed, sorted by decreasing weirdness.

---

## 💻 Technical Details

- **Input**:
  - Float values representing temperatures (in Celsius) via standard input.
  - The keyword `STOP` to terminate input.

- **Output Format**:
  Each temperature input (after enough data is gathered) is processed to display:
  ```
  g=<average> r=<relative>% s=<standard deviation> [a switch occurs]
  ```

- **Error Handling**:
  - Incorrect usage or invalid data causes the program to exit with code **84**.
  - Temperatures below -273.15°C are considered invalid.

- **Compilation**:
  - The project is compiled via a Makefile (supports `re`, `clean`, and `fclean` rules).

---

## 📂 Project Structure

- **groundhog**:
  - Main Python script implementing the forecast calculations.

- **Makefile**:
  - Contains rules to compile the binary, clean up, and rebuild.

- **bonus/**:
  - (Optional) Directory for bonus files, such as a specialized Makefile or extra features.

---

## 🏆 Evaluation Criteria

- **Functionality** ✅:
  - Correct computation of the temperature average, evolution, and standard deviation.
  - Accurate detection of trend switches and weather aberrations.

- **Error Handling** 🚨:
  - Robust management of invalid inputs with proper exit code (84).

- **Code Quality** 🧹:
  - Well-structured, readable, and maintainable code.

- **Output Formatting** 🎯:
  - Strict adherence to the specified output format.
