add_executable(file_sanitizer_test test.cpp)

add_library(file_reader_mock OBJECT file_reader_mock.cpp)
target_link_libraries(file_reader_mock gmock)
get_target_property(sut_include_dir FileSanitizer::Lib INCLUDE_DIRECTORIES)
target_include_directories(file_reader_mock PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${sut_include_dir}
    )
add_library(Mock::FileReader ALIAS file_reader_mock)

target_link_libraries(file_sanitizer_test
    FileSanitizer::Lib::file_sanitizer
    GTest::GTest
    Mock::FileReader
    GTest::Main 
    Threads::Threads
    )

target_include_directories(file_sanitizer_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME file_sanitizer_test COMMAND $<TARGET_FILE:file_sanitizer_test>)