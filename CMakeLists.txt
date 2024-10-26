cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_TOOLCHAIN_FILE /home/aurora/Applications/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_FLAGS "-Wall ${CMAKE_CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(qrc-decoder LANGUAGES CXX)

add_subdirectory(src/utils)

add_executable(demo src/main.cc)

target_include_directories(
    demo PUBLIC
    src/utils/include
)

target_link_libraries(
    demo PUBLIC
    utils
)
