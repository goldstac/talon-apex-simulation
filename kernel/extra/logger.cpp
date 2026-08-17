#include "logger.h"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
namespace fs = std::filesystem;

static bool log_time_enabled = true;
static bool config_loaded = false;

void ensure_logger_config() {
    std::string conf_path = "filesystem/etc/talonlogd.conf";
    if (fs::exists(conf_path)) {
        std::ifstream conf(conf_path);
        std::string line;
        while (std::getline(conf, line)) {
            if (line.rfind("log_time_true", 0) == 0) {
                if (line.find("false") != std::string::npos) {
                    log_time_enabled = false;
                } else if (line.find("true") != std::string::npos) {
                    log_time_enabled = true;
                }
            }
        }
    } else {
        fs::create_directories("filesystem/etc");
        std::cout << "[talonlogd] Enable timestamps in logs? [true/false] > ";
        std::string answer;
        std::getline(std::cin, answer);
        log_time_enabled = true;
        if (answer == "false") {
            log_time_enabled = false;
        }
        std::ofstream conf(conf_path);
        conf << "log_time_true = " << (log_time_enabled ? "true" : "false") << "\n";
        std::cout << "[talonlogd] wrote " << conf_path << "\n";
    }
    config_loaded = true;
}

void log_event(const std::string& level, const std::string& message) {
    if (!config_loaded) {
        ensure_logger_config();
    }
    std::string log_dir = "filesystem/var/log";
    std::string log_path = log_dir + "/system.log";
    fs::create_directories(log_dir);
    std::ofstream log(log_path, std::ios::app);
    if (log_time_enabled) {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm* tm = std::localtime(&t);
        char ts[32];
        std::strftime(ts, sizeof(ts), "%Y-%m-%d %H:%M:%S", tm);
        log << "[" << ts << "] ";
    }
    log << "[" << level << "] " << message << "\n";
}

void log_info(const std::string& message)    { log_event("INFO", message); }
void log_warn(const std::string& message)    { log_event("WARN", message); }
void log_error(const std::string& message)   { log_event("ERROR", message); }
void log_critical(const std::string& message){ log_event("CRITICAL", message); }

std::string read_log() {
    std::ifstream file("filesystem/var/log/system.log");
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}