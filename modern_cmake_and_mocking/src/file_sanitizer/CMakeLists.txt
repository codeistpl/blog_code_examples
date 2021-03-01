# @copyright codeist.pl codeist@codeist.pl 2021. All rights reserved
cmake_policy(SET CMP0076 NEW)
function(DeclareInterfaceTargets prefix sources)
    foreach(source_file ${${sources}})                                                                          # for each implementation file
        get_filename_component(file_name ${source_file} NAME_WE)                                                # extract basename  
        set(target_name "alias_${file_name}_target")                                                            # define a target name base on filename
        add_library(${target_name} INTERFACE)                                                                   # create interface library of targate name
        target_sources(${target_name} INTERFACE ${source_file})                                                 # set target source property fot that target
        target_include_directories(${target_name} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)     # set include directory for that target
        add_library(${prefix}::${file_name} ALIAS ${target_name})                                               # and create library alias
    endforeach()
endfunction()

project(file_sanitizer_lib LANGUAGES CXX)

set (file_sanitizer_sources
        file_sanitizer.cpp 
        file_reader.cpp
    )

DeclareInterfaceTargets(FileSanitizer::Lib file_sanitizer_sources)

add_library(${PROJECT_NAME} OBJECT ${file_sanitizer_sources})

target_include_directories(${PROJECT_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

add_library(FileSanitizer::Lib ALIAS ${PROJECT_NAME})
