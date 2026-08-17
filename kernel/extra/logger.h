#ifndef LOGGER_H
#define LOGGER_H

#include <string>

void ensure_logger_config();
void log_event(const std::string& level, const std::string& message);
void log_info(const std::string& message);
void log_warn(const std::string& message);
void log_error(const std::string& message);
void log_critical(const std::string& message);
std::string read_log();

#endif