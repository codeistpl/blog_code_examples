#include <iostream>
#include <abs_config.h>
#include <network_service_config.h>
#include <memory>

int main (int argc, char* argv[]){
    auto config = std::make_unique<NetworkServiceConfig>("user", "password", "localhost");
    auto copy = config->clone();

    std::cout << dynamic_cast<NetworkServiceConfig*>(copy.get())->username << std::endl;

}