//
// Created by noituri on 12.10.2019.
//

#ifndef COLORBOT_UTILS_H
#define COLORBOT_UTILS_H

class utils {
private:
    static bool generate_image(const std::string& color);
    static bool should_generate_new_image(const std::string& name);
public:
    static std::string get_image(const std::string& name);
};

#endif //COLORBOT_UTILS_H
