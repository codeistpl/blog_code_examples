#pragma once
#include <string>
class FileReader{
    public:
    FileReader(const std::string& name);
    std::string read();
};