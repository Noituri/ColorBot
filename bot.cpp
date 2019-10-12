//
// Created by noituri on 11.10.2019.
//

#include "bot.h"
#include "utils.h"
#define EMBED_COLOR 16757299

void ColorBot::onMessage(SleepyDiscord::Message message) {
    if (message.author.bot)
        return;

    if (message.content == "#help") {
        SleepyDiscord::Embed embed;
        embed.title = "Help";
        embed.color = EMBED_COLOR;
        embed.description = "**How to use:**\n"
                            "Just type hex color in the chat, "
                            "bot will do the rest *(remember to put '#' before hex)*\n\n"
                            "**Example:**\n"
                            "```#FF00FF```\n"
                            "**Commands:**\n"
                            "**#help** - shows this message.\n"
                            "**#about** - information about this bot.";
        sendMessage(message.channelID, "", embed);
    } else if (message.content == "#about") {
        SleepyDiscord::Embed embed;
        embed.title = "About";
        embed.color = EMBED_COLOR;
        embed.description = "**Created by:**\n"
                            "Mikołaj '[Noituri](https://github.com/noituri)' Radkowski\n\n"
                            "**Source code:**\n"
                            "Link -> [click](https://github.com/noituri/ColorBot)\n"
                            "Discord Library -> [sleepy-discord](https://github.com/yourWaifu/sleepy-discord)\n\n"
                            "**Version:**\n"
                            "0.1 alpha";
        sendMessage(message.channelID, "", embed);
    } else if (message.startsWith("#")) {
        if (message.length() != 7)
            return;
        sendTyping(message.channelID);
        printf("Uploading image for %s color.\n", message.content.c_str());
        uploadFile(message.channelID, utils::get_image(message.content),"");
    }
}