//
// Created by noituri on 13.10.2019.
//

#ifndef COLORBOT_COLOR_H
#define COLORBOT_COLOR_H

#include "command.h"

class color : public command {
public:
    std::string get_name() override;
    std::string get_desc() override;
    void execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) override;
};


#endif //COLORBOT_COLOR_H
