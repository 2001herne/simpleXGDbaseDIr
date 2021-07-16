//
// Created by benjaminherne on 15/7/21.
//

#ifndef SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H
#define SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H

#include <vector>
#include <filesystem>

namespace BH::sXGDbd {
    using Path = std::filesystem::path;
    namespace Defaults {
        Path XDG_DATA_HOME();
        Path XDG_CONFIG_HOME();
        Path XDG_STATE_HOME();
        std::vector<Path> XDG_DATA_DIRS();
        std::vector<Path> XDG_CONFIG_DIRS();
        Path XDG_CACHE_HOME();
    };

    Path getXDG_DATA_HOME();
    Path getXDG_CONFIG_HOME();
    Path getXDG_STATE_HOME();
    std::vector<Path> getEnvPathArray(std::string envName);
    std::vector<Path> getXDG_DATA_DIRS();
    std::vector<Path> getXDG_DATA_DIRS_CONCAT();
    std::vector<Path> getXDG_CONFIG_DIRS();
    std::vector<Path> getXDG_CONFIG_DIRS_CONCAT();
    Path getXGD_CACHE_HOME();
    Path getXDG_RUNTIME_DIR();
}

#endif //SIMPLEXGDBASEDIR_SIMPLEXDBBASEDIR_H
