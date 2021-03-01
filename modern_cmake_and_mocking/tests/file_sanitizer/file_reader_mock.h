#pragma once

#include <gmock/gmock.h>

class FileReaderMock;
static FileReaderMock* instance = nullptr;

class FileReaderMock{
    public:
    static FileReaderMock* get_instance(){
        if (instance == nullptr)
            instance = new FileReaderMock();
        return instance;
    }
    static void remove_instance(){
        if (instance != nullptr)
            delete instance;
            instance = nullptr;
    }
    MOCK_METHOD0(read, std::string());
};