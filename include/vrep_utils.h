//
// Created by kganguly on 4/30/18.
//

#pragma once

#include <cstdlib>
#include<string>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <map>

extern "C" {
#include "extApi.h"
#include "extApiPlatform.h"
}

namespace vrep_utils {
    extern int _clientID;
    extern const std::string _remoteIP;
    extern int _port;
    extern float _sim_timestep;
    extern std::string _default_scene_name;
    extern std::string _default_handle;
    std::map<int, bool> _isStreamingInitialized;

    void launch_vrep();

    void setup_vrep_remote();

    void exit_vrep();

    void step_sim();

    void start_sim();

    void stop_sim();

    void pause_sim();

    void load_scene(std::string scene_name = _default_scene_name);

    int fetch_handle(std::string obj_name = _default_handle);

}
