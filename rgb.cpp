//
// Created by noituri on 12.10.2019.
//

#include <cmath>
#include "rgb.h"

unsigned char rgb::convert_hex_to_dec(std::string hex) {
    double dec = 0;

    for (int i = 0; i < 2; i++){
        char i1 = hex[i];

        if (i1 >= 48 && i1 <= 57)
            i1 -= 48;
        else if (i1 >= 65 && i1 <= 70)
            i1 -= 55;

        dec += i1 * pow(16, ((2 - i) - 1));
    }

    return (unsigned char)dec;
}

rgb::rgb(const std::string& hex) {
    if (hex.length() != 6)
        return;

    r = convert_hex_to_dec(hex.substr(0, 2));
    g = convert_hex_to_dec(hex.substr(2, 2));
    b = convert_hex_to_dec(hex.substr(0, 2));
}

rgb::rgb(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}