get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)


file(GLOB SRC ./*.cpp)
file(GLOB HDR ./*.h)
list(LENGTH SRC SRC_SIZE)
file(GLOB TESTS ./*_test.cpp)
list(LENGTH TESTS TESTS_SIZE)
file(GLOB MOCKS ./*_mock.cpp)
list(LENGTH MOCKS MOCKS_SIZE)

# list(REMOVE_ITEM SRC ${TESTS})

#executable

add_executable(${MODULE_NAME} ${SRC})
target_link_libraries(${MODULE_NAME} ${CONAN_LIBS})
target_include_directories(${MODULE_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

#tests
# find_package(Threads REQUIRED)
# find_package(GTest REQUIRED)

# foreach (TEST  ${TESTS})
#     get_filename_component(TEST_NAME ${TEST} NAME_WE)
#     message(${TEST_NAME})
#     add_executable(${TEST_NAME} ${TEST})
#     target_include_directories(${TEST_NAME} PUBLIC 
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
#     target_link_libraries(${TEST_NAME} ${MODULE_NAME} GTest::GTest GTest::Main ${CONAN_LIBS_FMT})        
#     add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
# endforeach(TEST)

#install
# install(TARGETS ${MODULE_NAME} DESTINATION "lib")
# install(FILES ${HDR} DESTINATION "include")
