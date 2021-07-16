//
// Created by benjaminherne on 15/7/21.
//

#include "../include/sXDGbd.h"

#include <iostream>
#include <stdexcept>

namespace BH::sXGDbd {
    namespace Defaults {
        Path XDG_DATA_HOME() {
            return Path(getenv("HOME")).append(".local/share");
        }

        Path XDG_CONFIG_HOME() {
            return Path(getenv("HOME")).append(".config");
        }

        Path XDG_STATE_HOME() {
            Path(getenv("HOME")).append(".local/state");
        }

        std::vector<Path> XDG_DATA_DIRS() {
            return {"/usr/local/share", "/usr/share"};
        }

        std::vector<Path> XDG_CONFIG_DIRS() {
            return {"/etc/xdg"};
        }

        Path XDG_CACHE_HOME() {
            return Path(getenv("HOME")).append(".cache");
        }
    }

    Path getXDG_DATA_HOME() {
        const char *envDataHome = getenv("XDG_DATA_HOME");
        return (envDataHome == nullptr) ? Defaults::XDG_DATA_HOME() : envDataHome;
    }

    Path getXDG_CONFIG_HOME() {
        const char *envConfigDir = getenv("XDG_CONFIG_DIR");
        return (envConfigDir == nullptr) ? Defaults::XDG_CONFIG_HOME() : envConfigDir;
    }

    Path getXDG_STATE_HOME() {
        const char *envStateHome = getenv("XDG_STATE_HOME");
        return (envStateHome == nullptr) ? Defaults::XDG_STATE_HOME() : envStateHome;
    }

    std::vector<Path> getEnvPathArray(std::string envName) {
        const char *envPaths = getenv(envName.c_str());
        if (envPaths == nullptr) {
            return {};
        } else {
            std::vector<Path> paths{};
            std::string envPathsSting = envPaths;
            std::size_t splitIndex;
            while ((splitIndex = envPathsSting.find(':')) != std::string::npos) {
                paths.emplace_back(envPathsSting.substr(0, splitIndex));
                envPathsSting = envPathsSting.substr(splitIndex + 1);
            }
            paths.emplace_back(envPathsSting);

            return paths;
        }
    }

    std::vector<Path> getXDG_DATA_DIRS() {
        auto paths = getEnvPathArray("XDG_DATA_DIRS");
        return paths.empty() ? Defaults::XDG_DATA_DIRS() : paths;
    }

    std::vector<Path> getXDG_DATA_DIRS_CONCAT() {
        auto dataDirs = getXDG_DATA_DIRS();
        dataDirs.push_back(getXDG_DATA_HOME());
        return dataDirs;
    }

    std::vector<Path> getXDG_CONFIG_DIRS() {
        auto paths = getEnvPathArray("XDG_CONFIG_DIRS");
        return paths.empty() ? Defaults::XDG_CONFIG_DIRS() : paths;
    }

    std::vector<Path> getXDG_CONFIG_DIRS_CONCAT() {
        auto configDirs = getXDG_CONFIG_DIRS();
        configDirs.push_back(getXDG_CONFIG_HOME());
        return configDirs;
    }

    Path getXGD_CACHE_HOME() {
        const char *envCacheHome = getenv("XDG_CACHE_HOME");
        return (envCacheHome == nullptr) ? Defaults::XDG_CACHE_HOME() : envCacheHome;
    }

    Path getXDG_RUNTIME_DIR() {
        const char *envRuntimeDir = getenv("XDG_RUNTIME_DIR");
        if (envRuntimeDir != nullptr) {
            return envRuntimeDir;
        } else {
            std::string err = "No value set for XDG_RUNTIME_DIR, no default provided by spec. You're on your own.";
            std::cerr << err << '\n';
            throw std::runtime_error(err);
        }
    }

}
