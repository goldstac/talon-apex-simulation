#include "update.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#ifdef _WIN32
const std::string UPDATE_PLATFORM = "windows.exe";
#elif __APPLE__
const std::string UPDATE_PLATFORM = "macos";
#else
const std::string UPDATE_PLATFORM = "linux";
#endif
const std::string UPDATE_VERSION = "0.0.1";

void run_update() {
  std::cout << "Checking for updates...\n";
  std::string latest;
#ifdef _WIN32
  {
    std::string api_cmd =
        "curl -s "
        "https://api.github.com/repos/goldstac/talon-apex-simulation/releases/"
        "latest";
    FILE *fp = popen(api_cmd.c_str(), "r");
    if (fp) {
      std::string response;
      char buf[256];
      while (fgets(buf, sizeof(buf), fp)) {
        response += buf;
      }
      pclose(fp);
      std::string key = "\"tag_name\"";
      size_t pos = response.find(key);
      if (pos != std::string::npos) {
        pos = response.find('"', pos + key.length() + 1);
        if (pos != std::string::npos) {
          size_t end = response.find('"', pos + 1);
          if (end != std::string::npos) {
            latest = response.substr(pos + 1, end - pos - 1);
          }
        }
      }
    }
  }
#else
  std::string api_cmd =
      "curl -s "
      "https://api.github.com/repos/goldstac/talon-apex-simulation/releases/"
      "latest | grep 'tag_name' | cut -d'\"' -f4";
  FILE *fp = popen(api_cmd.c_str(), "r");
  char buf[64];
  if (fp && fgets(buf, sizeof(buf), fp)) {
    pclose(fp);
    latest = std::string(buf);
    if (!latest.empty() && latest.back() == '\n')
      latest.pop_back();
  } else {
    if (fp)
      pclose(fp);
  }
#endif
  if (latest == "v" + UPDATE_VERSION) {
    std::cout << "Already up to date (v" << UPDATE_VERSION << ")\n";
  } else if (!latest.empty()) {
    std::cout << "Updating from v" << UPDATE_VERSION << " to " << latest
              << "...\n";
    std::string dl = "curl -L "
                     "https://github.com/goldstac/talon-apex-simulation/"
                     "releases/latest/download/talon-os-";
    dl += UPDATE_PLATFORM + " -o talon-os-" + UPDATE_PLATFORM + ".new";
    std::system(dl.c_str());
#ifndef _WIN32
    std::system(("chmod +x talon-os-" + UPDATE_PLATFORM +
                 ".new && mv talon-os-" + UPDATE_PLATFORM + ".new talon-os-" +
                 UPDATE_PLATFORM)
                    .c_str());
    std::cout << "Update applied. Type 'exit' and run ./talon-os-"
              << UPDATE_PLATFORM << " again.\n";
#else
    std::cout << "Update downloaded to talon-os-" << UPDATE_PLATFORM
              << ".new. Restart to use the new version.\n";
#endif
  } else {
    std::cout
        << "Failed to check for updates. Check your internet connection.\n";
  }
}
