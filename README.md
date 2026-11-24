# Astro Cargo Hauler

Space trading and market simulator game.

## Installation

Reverted from the original Java version to a more efficient C++ implementation.
Use cmake to build the project.
It is intended to be cross-platform.
FTXUI dependency will be pulled on the first build

Windows:
```
mkdir build; cd build
cmake -G "Ninja" -S .. -B . -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug -- -j 8
ctest --output-on-failure -C Debug
```
Linux:
```
rm -rf build
cmake -B build
cmake --build build
```

==For release builds, change `Debug` to `Release` in the above commands.==

## Contributions

Please follow the Issues and create necessary branches.
Thank you for your contribution to the project.

Follow this documentation for ftxui : https://arthursonzogni.github.io/FTXUI/
Big props to the author arthursonzogni and his github repo: https://github.com/ArthurSonzogni/FTXUI
