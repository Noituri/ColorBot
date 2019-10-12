//
// Created by noituri on 11.10.2019.
//

#include "bot.h"
#include "utils.h"

void ColorBot::onMessage(SleepyDiscord::Message message) {
    if (message.author.bot)
        return;
    if (message.startsWith("#")) {
        if (message.length() != 7)
            return;
        uploadFile(message.channelID, utils::get_image(message.content),"");
    }
}