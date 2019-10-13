//
// Created by noituri on 13.10.2019.
//

#include "help.h"

help::help(std::s
tring help_message) : help_message(help_message) {
    help_message += "**" + get_name() + "** - " + get_desc() + "\n";
}

std::string help::get_name() {
    return "#help";
}

std::string help::get_desc() {
    return "shows this message.";
}

void help::execute_cmd(SleepyDiscord::DiscordClient *session, SleepyDiscord::Message message) {
    SleepyDiscord::Embed embed;
    embed.title = "Help";
    embed.color = EMBED_COLOR;
    embed.description = "**How to use:**\n"
                        "Just type hex color in the chat, "
                        "bot will do the rest *(remember to put '#' before hex)*\n\n"
                        "**Example:**\n"
                        "```#FF00FF```\n"
                        "**Commands:**\n" + help_message;
    session->sendMessage(message.channelID, "", embed);
}