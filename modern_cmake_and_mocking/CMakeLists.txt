# @copyright codeist.pl codeist@codeist.pl 2021. All rights reserved

cmake_minimum_required(VERSION 3.10)
project(FileSanitizer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(GNUInstallDirs)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
