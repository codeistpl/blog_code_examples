#include <arg_parser.h>
#include <cracker.h>

#include <chrono>
#include <iostream>

using namespace arg_parser;

int main(int argc, char const *argv[]) {
    ArgParser parser("Cracks SHA-256 hashed passwords with dictionaries!");
    parser.add_arg(make_flag("--help", "-h", "Prints help message"));
    parser.add_arg(make_arg("--hashed_value", "-v", "hashed password"));
    parser.add_arg(
        make_arg("--dictionaries_dir", "-d", "location of a dictionaries"));
    try {
        auto args = parser.parse_args(argc, argv);
        if (args.contains("--help")) {
            parser.print_help();
        }

        if (not args.contains("--hashed_value")) {
            std::cerr << "please pass --hashed_value" << std::endl;
            return 1;
        }

        if (not args.contains("--dictionaries_dir")) {
            std::cerr << "please pass --dictionaries_dir" << std::endl;
            return 1;
        }
        auto start = std::chrono::high_resolution_clock::now();
        auto password = crack_my_password(args["--hashed_value"],
                                          args["--dictionaries_dir"]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "time elapsed "
                  << " ints : " << diff.count() << " s\n";
        if (password.empty()) {
            std::cerr << "Cannot crack " << args["--hashed_value"] << std::endl;
            return -1;
        } else {
            std::cout << "Password for " << args["--hashed_value"] << " is "
                      << password << std::endl;
        }

    } catch (ArgParser::UndefinedArg &exception) {
        std::cerr << exception.what();
        return 1;
    }
    return 0;
}
