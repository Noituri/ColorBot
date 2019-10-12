//
// Created by noituri on 12.10.2019.
//

#ifndef COLORBOT_RGB_H
#define COLORBOT_RGB_H

#include <iostream>

class rgb {
private:
    static unsigned char convert_hex_to_dec(std::string hex);
public:
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    rgb(const std::string& hex);
    rgb(unsigned char r, unsigned char g, unsigned char b);
};


#endif //COLORBOT_RGB_H
