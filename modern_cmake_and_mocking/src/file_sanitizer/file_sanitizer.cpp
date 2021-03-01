#include <file_sanitizer.h>
#include <file_reader.h>

namespace file_sanitizer{
    bool sanitize_file(const std::string& file_name){
        auto content = FileReader(file_name).read();
        return content.find("error") == std::string::npos;
    }
}