project(lunar)

cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 14)
set(LUNAR_MAJOR_VERSION 0)
set(LUNAR_MINOR_VERSION 0)
set(LUNAR_BUILD_VERSION 0)
set(LUNAR_VERSION ${LUNAR_MAJOR_VERSION}.${LUNAR_MINOR_VERSION}.${LUNAR_BUILD_VERSION})

option(LUNAR_BUILD_SHARED "BUILD_SHARED" ON)
option(LUNAR_BUILD_STATIC "BUILD_STATIC" ON)

add_subdirectory(lib)

add_subdirectory(tests)

enable_testing()
