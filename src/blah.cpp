//
// Created by kganguly on 5/1/18.
//

#include "blah.h"

int main(int argc, char *argv[]) {
    int path_handle = -1;
    int dummy_handle = -1;
    float *pos_eul;
    float percent_path = 0.1;
    int count_pos_eul = 6;
    float *path_pos_eul;
//    vrep_utils::launch_vrep();

    vrep_utils::setup_vrep_remote();

    try {
        if (simxGetConnectionId(vrep_utils::_clientID) != -1) {
//            vrep_utils::load_scene();
            vrep_utils::start_sim();
            path_handle = vrep_utils::fetch_handle("Path");

            while (simxGetConnectionId(vrep_utils::_clientID) != -1) {
                simxCallScriptFunction(vrep_utils::_clientID, "Path", sim_scripttype_childscript, "fetchPath_function",
                                       0, NULL,
                                       1, &percent_path, 0, NULL, 0, NULL, NULL, NULL, &count_pos_eul, &path_pos_eul,
                                       NULL, NULL, NULL, NULL, simx_opmode_blocking);
            }
        }
    } catch (char *msg) {
        std::cout << msg << std::endl;
    }
}