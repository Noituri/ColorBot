//
// Created by noituri on 12.10.2019.
//

#ifndef COLORBOT_RGB_H
#define COLORBOT_RGB_H

#include <iostream>

class rgb {
private:
    unsigned char convert_hex_to_dec(std::string hex);
	std::string rgb::get_hex_from_char(unsigned char hex);
public:
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    rgb(const std::string& hex);
	rgb(int dec);
    rgb(unsigned char r, unsigned char g, unsigned char b);
	std::string get_hex();
};


#endif //COLORBOT_RGB_H
