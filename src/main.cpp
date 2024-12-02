#include <dpp/dpp.h>
#include <cstdlib>
#include <fstream>
#include <sys/utsname.h>

std::string get_system_info() {
    struct utsname sys_info;
    if (uname(&sys_info) == 0) {
        std::string info = "System: " + std::string(sys_info.sysname) + "\n" +
                           "Name: " + std::string(sys_info.nodename) + "\n" +
                           "Version: " + std::string(sys_info.release) + "\n" +
                           "Architecture: " + std::string(sys_info.machine) + "\n";
        return info;
    } else {
        return "Error: NTM.\n";
    }
}

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

int main(int argc, char **argv) {
    (void)argc;
    dpp::cluster bot(get_token(argv[1]));

    bot.on_slashcommand([](auto event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
        if (event.command.get_command_name() == "os") {
            event.reply(get_system_info());
        }
    });

    bot.on_ready([&bot](auto event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            bot.global_command_create(
                dpp::slashcommand("os", "Get OS information.", bot.me.id));
        }
    });
    bot.start(dpp::st_wait);
    return 0;
}
