#include <abs_config.h>
#include <string>

class NetworkServiceConfig : public Config<NetworkServiceConfig>{
    public:
        std::string username;
        std::string password;
        std::string address;

        NetworkServiceConfig(const std::string& username, const std::string& password, const std::string& address);
        

};