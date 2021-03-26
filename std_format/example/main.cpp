#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>

using namespace fmt;
using namespace std;

int main(int argc, char const *argv[]) {

    cout << format("┌{0:─^{2}}┐\n"
                   "│{1: ^{2}}│\n"
                   "└{0:─^{2}}┘\n",
                   "", "Hello, world!", 20);

    cout << format("Characters: {} {} \n", 'a', static_cast<char>(65));
    cout << format("Decimals: {} {}\n", 1977, 650000L);
    cout << format("Decimal whithin space of 10 characters: {:10} {} \n", 1977,
                   650000L);
    cout << format(
        "Decimal whithin space of 10 characters aligned left: {:<10}.\n", 1977);
    cout << format("Decimal whithin space of 10 characters aligned right, "
                   "preceding zeros: {:0>10}.\n",
                   1977);

    cout << format("Decimal whithin space of 10 characters aligned center, "
                   "surrounded *: {:*^10}.\n",
                   1977);

    cout << format("Float: {} .\n", -0.0000199999f);
    cout << format("Float with 5 digit precision: {:.5f} .\n", -0.0000199999f);
    cout << format("Padded hex {:#04x} \n", 0);

    cout << format("indexed arguments {0}, {1}, {0}", "zero", "first")
         << std::endl;

    cout << format("named arguments: {name}, {surename}",
                   arg("name", "my name"), arg("surename", "my familly name"))
         << endl;
    cout << format("date formatting: {:%Y-%m-%d}", localtime(time(nullptr)))
         << endl;

    return 0;
}
