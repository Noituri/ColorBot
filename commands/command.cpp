//
// Created by noituri on 12.10.2019.
//

#include "command.h"

void command::send_error(SleepyDiscord::DiscordClient* session, std::string message, std::string channel_id) {
	SleepyDiscord::Embed embed;
	embed.title = "Error";
	embed.color = ERROR_EMBED_COLOR;
	embed.description = message;
	session->sendMessage(channel_id, "", embed);
}