//
// Created by kganguly on 5/15/18.
//

#include "example_path.h"

int main(int argc, char *argv[]) {


//    vrep_utils::launch_vrep();
    vrep_utils::setup_vrep_remote();

    try {
        if (simxGetConnectionId(vrep_utils::_clientID) != -1) {
            vrep_utils::load_scene();
            vrep_utils::start_sim();

            vrep_path::_path_name = "Path";
            vrep_path::_path_handle = vrep_utils::fetch_handle(vrep_path::_path_name);
            vrep_path::_path_function = "fetchPath_function";
            vrep_path::_percent_of_path = 0.1;
            int i = 0;
            while (simxGetConnectionId(vrep_utils::_clientID) != -1) {

                vrep_path::_percent_of_path = 0.1 + i;
                std::vector<float> vrep_vals = vrep_path::fetch_path_data_from_relative_position();
                for (int i = 0; i < vrep_path::_count_floats_from_server; ++i) {
                    std::cout << vrep_vals[i] << " ";
                }
                std::cout << std::endl;
                i += 0.1;
                vrep_utils::step_sim();
            }
        }
    } catch (char *msg) {
        vrep_utils::stop_sim();
        std::cout << msg << std::endl;
    }

    return 0;
}