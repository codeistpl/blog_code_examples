#include <gtest/gtest.h>
#include <file_reader_mock.h>
#include <file_sanitizer.h>

using ::testing::Return;

TEST(MyTest, call_mock){
    auto mock = FileReaderMock::get_instance();
    EXPECT_CALL(*mock, read()).WillOnce(Return("hellp"));
    EXPECT_TRUE ( file_sanitizer::sanitize_file(""));
    FileReaderMock::remove_instance();

}
