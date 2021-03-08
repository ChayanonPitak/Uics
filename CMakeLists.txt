cmake_minimum_required(VERSION 3.18)

project(main CXX)
set(CMAKE_CXX_STANDARD 17)
set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.boost.serialization-1.75.0
    org.sw.demo.boost.core-1.75.0
    org.sw.demo.boost.thread-1.75.0
    org.sw.demo.boost.math-1.75.0
    org.sw.demo.boost.random-1.75.0
    org.sw.demo.boost.exception-1.75.0
    org.sw.demo.boost.regex-1.75.0
    org.sw.demo.boost.container-1.75.0
    org.sw.demo.wxwidgets.core-3.1.4
    org.sw.demo.wxwidgets.base-3.1.4
    org.sw.demo.google.tesseract.libtesseract-master
    org.sw.demo.danbloomberg.leptonica-1.80.0
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

# add include dir
include_directories(include/)
file(GLOB SOURCES "./src/*.cpp")

add_executable(main WIN32 ${SOURCES})
target_link_libraries(main ${DEPENDENCIES})

