//
// Created by noituri on 11.10.2019.
//

#ifndef COLORBOT_BOT_H
#define COLORBOT_BOT_H
#include <sleepy_discord/websocketpp_websocket.h>
#include "commands/command.h"

class ColorBot : public SleepyDiscord::DiscordClient {
private:
    std::vector<std::unique_ptr<command>> commands;
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void start();
    void onMessage(SleepyDiscord::Message message) override;
};


#endif //COLORBOT_BOT_H
