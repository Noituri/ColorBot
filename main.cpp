#include <toml.hpp>
#include "bot.h"

int main() {
    const auto data  = toml::parse("config.toml");
    const auto token = toml::find<std::string>(data, "token");

    ColorBot client(token, 2);
    client.run();
}