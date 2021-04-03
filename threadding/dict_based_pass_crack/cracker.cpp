#include <cracker.h>
#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <openssl/sha.h>
#include <queue>
#include <sstream>

namespace fs = std::filesystem;

namespace {

std::string sha256(const std::string &str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(hash[i]);
    }
    return ss.str();
}
} // namespace

std::string bruteforce_with_dict(const std::string &hash,
                                 const fs::path &file_path) {
    unsigned int counter = 0;
    std::ifstream infile(file_path);
    std::string word;
    while (infile >> word) {
        auto word_hash = sha256(word);
        if (hash == word_hash) {
            std::cout << "finishing: " << file_path << std::endl;
            return word;
        }
        counter++;
    }
    std::cout << "finishing: " << file_path << std::endl;
    std::cout.flush();
    return {};
}

std::string crack_my_password(const std::string &hash,
                              const std::string &path) {
    std::cout << "cracking " << hash << " with: " << path << std::endl;
    auto processor_count = std::thread::hardware_concurrency();
    std::queue<std::future<std::string>> tasks;
    for (const auto &entry : fs::directory_iterator(path)) {

        if (tasks.size() > processor_count) {
            auto word = tasks.front().get();
            tasks.pop();
            if (not word.empty())
                return word;
        } else {
            std::cout << "starting " << entry.path() << std::endl;
            tasks.push(std::async(&bruteforce_with_dict, hash, entry.path()));
        }
    }

    while (not tasks.empty()) {
        std::cout << "cleanup\n";
        auto word = tasks.front().get();
        tasks.pop();
        if (not word.empty())
            return word;
    }
    return {};
}