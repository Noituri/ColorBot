//
// Created by noituri on 11.10.2019.
//

#include "bot.h"

#include <memory>
#include "utils.h"
#include "commands/hextoimage.h"
#include "commands/about.h"
#include "commands/help.h"

void ColorBot::start() {
	// put every new command here
    commands.push_back(std::make_unique<about>());

    std::string help_message;
    for (auto const& cmd : commands) {
        if (cmd->get_desc().empty())
            continue;
        help_message += "**" + cmd->get_name() + "** - " + cmd->get_desc() + "\n";
    }

    commands.push_back(std::make_unique<help>(help_message));
	commands.push_back(std::make_unique<hextoimage>());


    this->run();
}

void ColorBot::onMessage(SleepyDiscord::Message message) {
    if (message.author.bot)
        return;

    for (auto const& cmd : commands) {
        if (message.startsWith(cmd->get_name())) {
            cmd->execute_cmd(this, message);
            break;
        }
    }
}