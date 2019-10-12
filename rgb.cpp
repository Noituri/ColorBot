//
// Created by noituri on 12.10.2019.
//

#include <sstream>
#include "rgb.h"

unsigned char rgb::convert_hex_to_dec(std::string hex) {
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> x;

    return (unsigned char)x;
}

rgb::rgb(const std::string& hex) {
    if (hex.length() != 6)
        return;

    r = convert_hex_to_dec(hex.substr(0, 2));
    g = convert_hex_to_dec(hex.substr(2, 2));
    b = convert_hex_to_dec(hex.substr(4, 2));
}

rgb::rgb(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}