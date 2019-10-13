//
// Created by noituri on 12.10.2019.
//

#ifndef COLORBOT_COMMAND_H
#define COLORBOT_COMMAND_H

#define EMBED_COLOR 16757299
#define ERROR_EMBED_COLOR 16711680

#include <string>
#include <sleepy_discord/websocketpp_websocket.h>

class command {
public:
	virtual void send_error(SleepyDiscord::DiscordClient* session, std::string message, std::string channel_id);
	virtual std::string get_name() = 0;
    virtual std::string get_desc() = 0;
    virtual void execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) = 0;
};

#endif //COLORBOT_COMMAND_H
