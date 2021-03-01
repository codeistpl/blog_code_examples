#include <file_reader.h>
#include <string>
#include <gmock/gmock.h>
#include <file_reader_mock.h>


FileReader::FileReader(const std::string& ){
}

std::string FileReader::read(){
    return FileReaderMock::get_instance()->read();
}


