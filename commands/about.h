//
// Created by noituri on 13.10.2019.
//

#ifndef COLORBOT_ABOUT_H
#define COLORBOT_ABOUT_H

#include "command.h"

class about : public command {
public:
    std::string get_name() override;
    std::string get_desc() override;
    void execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) override;
};


#endif //COLORBOT_ABOUT_H
