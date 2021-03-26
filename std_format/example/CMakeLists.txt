get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB SRC ./*.cpp)

message("src" ${SRC})
add_executable(${MODULE_NAME} ${SRC})
target_link_libraries(${MODULE_NAME} fmt)

