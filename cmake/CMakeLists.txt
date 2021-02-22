cmake_minimum_required(VERSION 3.19)

project(main CXX)
set(CMAKE_CXX_STANDARD 17)
set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.wxwidgets.core-3.1.4
    org.sw.demo.wxwidgets.base-3.1.4
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

# add include dir
include_directories(src/)

add_executable(main WIN32 src/mainApp.cpp)
target_link_libraries(main ${DEPENDENCIES})

