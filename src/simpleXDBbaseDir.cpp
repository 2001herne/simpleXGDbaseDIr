//
// Created by benjaminherne on 15/7/21.
//

#include "../include/simpleXDBbaseDir.h"

#include <iostream>
#include <stdexcept>

BH::sXGDbd::Path BH::sXGDbd::getXDG_DATA_HOME() {
    const char* envDataHome = getenv("XDG_DATA_HOME");
    return (envDataHome == nullptr) ? Defaults::XDG_DATA_HOME : envDataHome;
}

BH::sXGDbd::Path BH::sXGDbd::getXDG_CONFIG_HOME() {
    const char* envConfigDir = getenv("XDG_CONFIG_DIR");
    return (envConfigDir == nullptr) ? Defaults::XDG_CONFIG_HOME : envConfigDir;
}

BH::sXGDbd::Path BH::sXGDbd::getXDG_STATE_HOME() {
    const char* envStateHome = getenv("XDG_STATE_HOME");
    return (envStateHome == nullptr) ? Defaults::XDG_STATE_HOME : envStateHome;
}

std::vector<BH::sXGDbd::Path> BH::sXGDbd::getEnvPathArray(std::string envName) {
    const char* envPaths = getenv(envName.c_str());
    if (envPaths == nullptr) {
        return {};
    } else {
        std::vector<BH::sXGDbd::Path> paths {};
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

std::vector<BH::sXGDbd::Path> BH::sXGDbd::getXDG_DATA_DIRS() {
    auto paths = getEnvPathArray("XDG_DATA_DIRS");
    return paths.empty() ? Defaults::XDG_DATA_DIRS : paths;
}

std::vector<BH::sXGDbd::Path> BH::sXGDbd::getXDG_CONFIG_DIRS() {
    auto paths = getEnvPathArray("XDG_CONFIG_DIRS");
    return paths.empty() ? Defaults::XDG_CONFIG_DIRS : paths;
}

BH::sXGDbd::Path BH::sXGDbd::getXGD_CACHE_HOME() {
    const char* envCacheHome = getenv("XDG_CACHE_HOME");
    return (envCacheHome == nullptr) ? Defaults::XDG_CACHE_HOME : envCacheHome;
}

BH::sXGDbd::Path BH::sXGDbd::getXDG_RUNTIME_DIR() {
    const char* envRuntimeDir = getenv("XDG_RUNTIME_DIR");
    if (envRuntimeDir != nullptr) {
        return envRuntimeDir;
    } else {
        std::string err = "No value set for XDG_RUNTIME_DIR, no default provided by spec. You're on your own.";
        std::cerr << err << '\n';
        throw std::runtime_error(err);
    }
}
