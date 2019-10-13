//
// Created by noituri on 13.10.2019.
//

#ifndef COLORBOT_HELP_H
#define COLORBOT_HELP_H

#include "command.h"

class help : public command {
    std::string help_message;
public:
    help(std::string help_message);
    std::string get_name() override;
    std::string get_desc() override;
    void execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) override;
};


#endif //COLORBOT_HELP_H
