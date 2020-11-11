cmake_minimum_required(VERSION 3.16)
project(AdventOfC__)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdventOfC__ puzzle1.cpp puzzle2.cpp puzzle3.cpp puzzle4.cpp puzzle5.cpp puzzle6.cpp catch.hpp catch.cpp utils/md5.cpp utils/md5.h utils/file-io.h utils/file-io.cpp file-io-tests.cpp)