//
// Created by kganguly on 4/30/18.
//

#include "vrep_utils.h"


int vrep_utils::_clientID = -1;
const std::string vrep_utils::_remoteIP = "127.0.0.1";
int vrep_utils::_port = 19999;
float vrep_utils::_sim_timestep = .005;
std::string vrep_utils::_default_scene_name = "../scenes/sample.ttt";
std::string vrep_utils::_default_handle = "";


void vrep_utils::launch_vrep() {
    std::string vrep_path(
            "nohup /home/kanishka/Documents/Projects/VREP/V-REP_PRO_EDU_V3_5_0_Linux/vrep.sh &");
    int ret = std::system(vrep_path.c_str());
    usleep(5e+6);
    std::cout << "V-REP launched" << std::endl;
}

void vrep_utils::setup_vrep_remote() {
    std::cout << "Starting Remote API" << std::endl;
    try {
        _clientID = simxStart(_remoteIP.c_str(), _port, true, false, 5000, 5);
        if (_clientID == -1) {
            std::cout << "Failed to connect to Remote API server" << std::endl;
            vrep_utils::exit_vrep();
            exit(0);
        } else {
            std::cout << "Connected to V-REP" << std::endl;
        }
    } catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}


void vrep_utils::exit_vrep() {
    vrep_utils::stop_sim();
    simxFinish(_clientID);
}

void vrep_utils::start_sim() {
    simxSynchronous(_clientID, true);
    simxSetFloatingParameter(_clientID, sim_floatparam_simulation_time_step, _sim_timestep,
                             simx_opmode_oneshot);
    simxStartSimulation(_clientID, simx_opmode_blocking);
}


void vrep_utils::stop_sim() {
    simxStopSimulation(_clientID, simx_opmode_oneshot_wait);
}

void vrep_utils::pause_sim() {
    simxPauseSimulation(_clientID, simx_opmode_oneshot_wait);
}

void vrep_utils::step_sim() {
    simxSynchronousTrigger(_clientID);
}

void vrep_utils::load_scene(std::string scene_name) {
    std::cout << "Loading scene: " << scene_name.c_str() << std::endl;
    simxLoadScene(_clientID, (scene_name).c_str(), 0xFF, simx_opmode_blocking);
}

int vrep_utils::fetch_handle(std::string obj_name) {
    if (obj_name == "") {
        std::cout << "Enter correct object name." << std::endl;
        return -1;
    }
    int handle;
    simxGetObjectHandle(_clientID, obj_name.c_str(), &handle, simx_opmode_blocking);

    return handle;
}