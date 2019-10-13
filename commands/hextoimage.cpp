//
// Created by noituri on 12.10.2019.
//

#include "hextoimage.h"
#include "../utils.h"

std::string hextoimage::get_name() {
    return "#";
}

std::string hextoimage::get_desc() {
    return "";
}

void hextoimage::execute_cmd(SleepyDiscord::DiscordClient* session, SleepyDiscord::Message message) {
    if (message.length() != 7)
        return;
    session->sendTyping(message.channelID);

    auto t_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char* request_time = std::ctime(&t_time);
    printf("[%.24s] Uploading image for %s color.\n", request_time, message.content.c_str());
    session->uploadFile(message.channelID, utils::get_image(message.content), "");
}