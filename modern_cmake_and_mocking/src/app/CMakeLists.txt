add_executable(sanitize_file main.cpp)
target_link_libraries(sanitize_file
    FileSanitizer::Lib)

