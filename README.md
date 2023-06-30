# Overview

This sample application is originated from the nRF SDK blinky-sample.
Unit tests were added to demonstrate linker-substitution and provide a possible setup on how to add unit tests to an existing application

## How to build the unit tests

Easiest option is to execute the tests in WSL.

### Prerequisites (WSL)
- `sudo apt update && sudo apt install build-essential`
- `sudo apt install cmake`

### Build and execute the tests
- `cd test`
- `cmake -S . -B build`
- `cmake --build build`
- `cd build && ctest`