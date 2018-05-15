//
// Created by kganguly on 5/1/18.
//

#include <vector>
#include "blah.h"

int main(int argc, char *argv[]) {
    int path_handle = -1;
    int dummy_handle = -1;
    float percent_of_path = 0.1f;

    int count_floats_from_server;
    float *floats_from_server;

//    vrep_utils::launch_vrep();

    vrep_utils::setup_vrep_remote();

    try {
        if (simxGetConnectionId(vrep_utils::_clientID) != -1) {
//            vrep_utils::load_scene();
            vrep_utils::start_sim();
            path_handle = vrep_utils::fetch_handle("Path");

            while (simxGetConnectionId(vrep_utils::_clientID) != -1) {
                simxCallScriptFunction(vrep_utils::_clientID, "Path", sim_scripttype_childscript, "fetchPath_function",
                                       1, &path_handle,                   // input int count, input int data
                                       1, &percent_of_path,               // input float count, input float data
                                       0, NULL,                           // input string count, input string data
                                       0, NULL,                           // input buffer size, input buffer data
                                       NULL, NULL,                        // output int count, output int data
                                       &count_floats_from_server,
                                       &floats_from_server, // output float count, output float data
                                       NULL, NULL,                        // output string count, output string data
                                       NULL, NULL,                        // output buffer count, output buffer data
                                       simx_opmode_blocking);
                std::vector<float> vrep_vals(floats_from_server, floats_from_server + count_floats_from_server);
                for (int i = 0; i < count_floats_from_server; ++i) {
                    std::cout << vrep_vals[i] << " ";
                }
                std::cout << std::endl;
            }
        }
    } catch (char *msg) {
        vrep_utils::stop_sim();
        std::cout << msg << std::endl;
    }
}