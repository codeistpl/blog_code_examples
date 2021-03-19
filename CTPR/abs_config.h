#pragma once
#include <memory>

class AbsConfig{
public:
    virtual ~AbsConfig () = default;
    virtual std::unique_ptr<AbsConfig> clone() const = 0;

};

// This CRTP class implements clone() for Derived
template <typename Derived>
class Config : public AbsConfig {
public:
    std::unique_ptr<AbsConfig> clone() const override {
        return std::make_unique<Derived>(static_cast<Derived const&>(*this));
    }
    ~Config() = default;    

protected:
    Config() = default;
    Config(const Config&) = default;
    Config(Config&&) = default;
};
