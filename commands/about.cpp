//
// Created by noituri on 13.10.2019.
//

#include "about.h"

std::string about::get_name() {
    return "#about";
}

std::string about::get_desc() {
    return "information about this bot.";
}

void about::execute_cmd(SleepyDiscord::DiscordClient *session, SleepyDiscord::Message message) {
    SleepyDiscord::Embed embed;
    embed.title = "About";
    embed.color = EMBED_COLOR;
    embed.description = "**Created by:**\n"
                        "Mikołaj '[Noituri](https://github.com/noituri)' Radkowski\n\n"
                        "**Source code:**\n"
                        "Link -> [click](https://github.com/noituri/ColorBot)\n"
                        "Discord Library -> [sleepy-discord](https://github.com/yourWaifu/sleepy-discord)\n\n"
                        "**Version:**\n"
                        "0.0.1 alpha";
    session->sendMessage(message.channelID, "", embed);
}