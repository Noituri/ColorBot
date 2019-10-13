//
// Created by noituri on 12.10.2019.
//

#ifndef COLORBOT_HEXTOIMAGE_H
#define COLORBOT_HEXTOIMAGE_H


#include "command.h"

class hextoimage : public command {
public:
    std::string get_name() override;
    std::string get_desc() override;
    void execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) override;
};


#endif //COLORBOT_HEXTOIMAGE_H
