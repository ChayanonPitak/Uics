# **Uics** (University schedule .ics creator.)

## Requirements
- **CMake** version 3.18 (VS built in) or more (https://cmake.org/install/)
- **sw (software network)** version 1.0.0 or more (https://software-network.org/) 
- - Don't forget to run ```sw setup```
- **eng.traineddata** (https://github.com/tesseract-ocr/tessdata_best) P
- - Put it in ```/build/tessdata```

### How to build on cmake.
1. cmake -Bbuild
2. cd build
3. cmake --build .
4. .exe file shoud be in ./build/Debug

## Milestone

### Schedule input

- [ ] **Course schedule input.**
- [ ] Class schedule.
- [ ] Examination schedule.
- [ ] **Semester period & holiday input.**
- [x] Semester period.
- [x] Examination period.
- [ ] **Holiday**
- [ ] *Bonus : Get holiday data from API.*
- [x] **Schedule list.**

### Save & Exporting.

- [x] Export to .ics
- [x] Save to custom file.
- [x] Load from custom file.


## License

This program and source code is licened under [MIT License](https://opensource.org/licenses/MIT).  
For more information please see [the license file](LICENSE).
