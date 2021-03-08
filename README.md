# **Uics** (University schedule .ics creator.)

This application use wxWidgets 3.1.4 for GUI library.  
Please install the library [here](https://www.wxwidgets.org/downloads/)  
Build and [setup the environment variable](https://wiki.wxwidgets.org/Adding_an_Environment_Variable_under_Windows) to make the program compile  correctly.

# Requirements
- CMake version > 3.19 (https://cmake.org/install/)
- sw (software network) version > 1.0.0 (https://software-network.org/) and don't forget to run ```sw setup```
- eng.traineddata (https://github.com/tesseract-ocr/tessdata_best) and put it in ```/build/tessdata```

# How to
1. cmake -Bbuild
2. cd build
3. cmake --build .
4. exe file shoud be in ./build/Debug

# Milestone

### Schedule input

- [ ] **Course schedule input.**
- [x] Class schedule.
- [ ] Examination schedule.
- [ ] **Semester period & holiday input.**
- [ ] Semester period.
- [ ] Examination period.
- [ ] **Hoiday**
- [ ] *Bonus : Get holiday data from API.*
- [ ] **Schedule list.**

### Save & Exporting.

- [ ] Export to .ics
- [ ] Save to custom file.
- [ ] Load from custom file.


# License

This program and source code is licened under [MIT License](https://opensource.org/licenses/MIT).  
For more information please see [the license file](LICENSE).
