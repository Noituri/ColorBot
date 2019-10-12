//
// Created by noituri on 12.10.2019.
//

#include <iostream>
#include <filesystem>
#include "utils.h"
#include "rgb.h"
#include <lodepng.h>


bool utils::should_generate_new_image(const std::string& name) {
    if (!std::filesystem::exists("colors"))
        std::filesystem::create_directory("colors");

    return !std::filesystem::exists("colors/" + name);
}

bool utils::generate_image(const std::string& color) {
    lodepng::State state;
    rgb rgb_color(color);

    for(int i = 0; i < 16; i++) {
        unsigned char a = 255;

        lodepng_palette_add(&state.info_png.color, rgb_color.r, rgb_color.g, rgb_color.b, a);
        lodepng_palette_add(&state.info_raw, rgb_color.r, rgb_color.g, rgb_color.b, a);
    }

    state.info_png.color.colortype = LCT_PALETTE;
    state.info_png.color.bitdepth = 4;
    state.info_raw.colortype = LCT_PALETTE;
    state.info_raw.bitdepth = 4;
    state.encoder.auto_convert = 0;

    const unsigned w = 250;
    const unsigned h = 250;
    std::vector<unsigned char> image(w*h);

    std::vector<unsigned char> buffer;
    unsigned error = lodepng::encode(buffer, image.empty() ? nullptr : &image[0], w, h, state);
    if(error) {
        std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
        return true;
    }

    lodepng::save_file(buffer, "colors/" + color + ".png");
    lodepng_state_cleanup(&state);

    return false;
}

std::string utils::get_image(const std::string& name) {
    std::string image_name = name;
    if (image_name.front() == '#') {
        image_name.erase(0, 1);
    }

    if (should_generate_new_image(image_name + ".png"))
        generate_image(image_name);

    return "colors/" + image_name + ".png";
}