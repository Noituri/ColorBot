//
// Created by noituri on 11.10.2019.
//

#ifndef COLORBOT_BOT_H
#define COLORBOT_BOT_H
#include <sleepy_discord/websocketpp_websocket.h>


class ColorBot : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override;
};


#endif //COLORBOT_BOT_H
