# @copyright codeist.pl codeist@codeist.pl 2021. All rights reserved

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

project(ctpr)

add_executable(ctpr main.cpp network_service_config.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} )