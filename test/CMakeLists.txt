cmake_minimum_required(VERSION 3.19)

project(main CXX)
set(CMAKE_CXX_STANDARD 17)
set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.boost.serialization-1.75.0
    org.sw.demo.boost.core-1.75.0
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

# add include dir
include_directories(../)

add_executable(main main.cpp)
target_link_libraries(main ${DEPENDENCIES})
