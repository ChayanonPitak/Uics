cmake_minimum_required(VERSION 3.19)

project(with_ocr CXX)
set(CMAKE_CXX_STANDARD 17)
set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.google.tesseract.libtesseract-master
    org.sw.demo.danbloomberg.leptonica-1.80.0
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

include_directories(include/)

# if building GUI add WIN32 after main
add_executable(main with_ocr.cpp)
target_link_libraries(main ${DEPENDENCIES})

install(TARGETS main DESTINATION bin)