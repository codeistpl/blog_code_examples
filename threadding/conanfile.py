from conans import ConanFile, CMake


class ArgumentParser(ConanFile):
    name = "cracker"
    version = "0.0.0"
    license = "MIT"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "Simple argument parser for CLI in C++"
    settings = "os", "compiler", "build_type", "arch"
    requires = [
        "gtest/1.10.0",
        "fmt/7.1.3",  # std::format implementation
        "arg_parser/0.0.0@codeist/testing",
        "openssl/1.1.1k"
    ]
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake", "cmake_paths"
    exports_sources = "*"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["arg_parser"]
