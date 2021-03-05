# CMake build system for main branch
I'll try to keep this up to date with main branch

# Requirements
- CMake version > 3.19 (https://cmake.org/install/)
- sw (software network) version > 1.0.0 (https://software-network.org/) and don't forget to run ```sw setup```

# Build steps
1. git clone https://github.com/ChayanonPitak/Uics
2. cd Uics
3. cmake -Scmake -Bbuild
4. cd build
5. cmake --build .
6. exe file shoud be in ./build/Debug