project(arg_parser)
cmake_minimum_required(VERSION 3.15)
set( CMAKE_CXX_STANDARD 20)
set( CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options( -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast 
                    -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion 
                    -Wsign-conversion -Wmisleading-indentation  -Wduplicated-cond -Wduplicated-branches 
                    -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/gcovr.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(GNUInstallDirs)

conan_basic_setup()

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

enable_testing()
add_subdirectory(dict_based_pass_crack)
