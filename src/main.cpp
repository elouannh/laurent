#include <dpp/dpp.h>
#include <cstdlib>
#include <fstream>

std::string get_token(const char *filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: NTM." << std::endl;
        return NULL;
    }
    std::string line;
    std::getline(file, line);
    file.close();
    return line;
}

int main() {
    dpp::cluster bot(get_token(".ohptnlaurent"));

    bot.on_slashcommand([](auto event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](auto event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });
    bot.start(dpp::st_wait);
    return 0;
}
