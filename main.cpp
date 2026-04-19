#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string>
void showNotification(std::string seconds, std::string reason) {
    std::string parsed = "Timer for " + reason + " has ended after " + seconds;
    std::string cmd = "zenity --info --title='Timer has ended' --text='" + parsed + "'";
    system(cmd.c_str());
}

int convertoseconds(std::string time) {
    std::string sub = time.substr(time.size() - 1);
    if (sub == "s") {
        return std::stoi(time);
    } else if (sub == "m") {
        return std::stoi(time) * 60;
    } else if (sub == "h") {
        return std::stoi(time) * 3600;
    } else {
        throw std::invalid_argument("Invalid time format. Use 's' for seconds, 'm' for minutes, or 'h' for hours.");
    }

}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <reason> <duration>" << std::endl;
        return 1;
    }

    std::string reason = argv[1];
    std::string duration = argv[2];

    int time = convertoseconds(duration);
    while (time > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time--;
    }
    showNotification(argv[2], reason);
    return 0;
}
