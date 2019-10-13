//
// Created by noituri on 13.10.2019.
//

#include "color.h"
#include "../rgb.h"

std::string color::get_name() {
    return "#color";
}

std::string color::get_desc() {
    return "gets color of mentioned role";
}

void color::execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) {
	if (message.mentionRoles.empty()) {
		send_error(session, "Please mention some role", message.channelID);
		return;
	}

	for (auto const& role : session->getRoles(message.serverID).list()) {
		if (role.ID == message.mentionRoles.at(0).string()) {
			rgb role_rgb(role.color);

			SleepyDiscord::Embed embed;
			embed.title = "Color for '" + role.name + "' role:";
			embed.color = role.color;
			embed.description = "#" + role_rgb.get_hex();
			session->sendMessage(message.channelID, "", embed);
		}
	}
}