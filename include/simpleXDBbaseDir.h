//
// Created by benjaminherne on 15/7/21.
//

#ifndef SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H
#define SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H

#include <vector>
#include <filesystem>

#define SIC static inline const

namespace BH::sXGDbd {
    using Path = std::filesystem::path;
    struct Defaults {
        SIC Path XDG_DATA_HOME = Path(getenv("HOME")).append(".local/share");
        SIC Path XDG_CONFIG_HOME = Path(getenv("HOME")).append(".config");
        SIC Path XDG_STATE_HOME = Path(getenv("HOME")).append(".local/state");
        SIC std::vector<Path> XDG_DATA_DIRS = {"/usr/local/share", "/usr/share"};
        SIC std::vector<Path> XDG_CONFIG_DIRS = {"/etc/xdg"};
        SIC Path XDG_CACHE_HOME = Path(getenv("HOME")).append(".cache");
    };

    Path getXDG_DATA_HOME();
    Path getXDG_CONFIG_HOME();
    Path getXDG_STATE_HOME();
    std::vector<Path> getEnvPathArray(std::string envName);
    std::vector<Path> getXDG_DATA_DIRS();
    std::vector<Path> getXDG_CONFIG_DIRS();
    Path getXGD_CACHE_HOME();
    Path getXDG_RUNTIME_DIR();
}

#endif //SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H
