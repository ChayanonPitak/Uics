cmake_minimum_required(VERSION 3.19)

project(wiht_ocr CXX)
set(CMAKE_CXX_STANDARD 14)
set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.google.tesseract.libtesseract-master
    org.sw.demo.danbloomberg.leptonica-1.80.0
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${DEPENDENCIES})