# Astro Cargo Hauler

Space trading and market simulator game.

---

## Installation

Reverted from the original Java version to a more efficient C++ implementation.
Use cmake to build the project.
It is intended to be cross-platform.

Windows:
```
mkdir build; cd build
cmake -G "Ninja" -S .. -B . -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug -- -j 8
ctest --output-on-failure -C Debug
```
Linux:
```
mkdir -p build && cd build
cmake -G "Ninja" -S .. -B . -DCMAKE_BUILD_TYPE=Debug
cmake --build . --j$(nproc)
ctest --output-on-failure -C Debug
```

==For release builds, change `Debug` to `Release` in the above commands.==

## Contribution

Please follow the Issues and create necessary branches.
Thank you for your contribution to the project.