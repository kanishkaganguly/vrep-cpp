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
            int kinect_handle = vrep_utils::fetch_handle("kinect");
            vrep_path::_path_function = "fetchPath_function";
            vrep_path::_percent_of_path = 0.0;
            vrep_path::_path_increment = 1e-3;

            while (simxGetConnectionId(vrep_utils::_clientID) != -1) {
                std::vector<float> pose_on_path = vrep_path::fetch_path_data_from_relative_position(
                        vrep_utils::_clientID);
                std::cout << vrep_path::_percent_of_path << " := ";
                for (int i = 0; i < vrep_path::_count_floats_from_server; ++i) {
                    std::cout << pose_on_path[i] << " ";
                }
                std::cout << std::endl;

                vrep_path::move_object_on_path(vrep_utils::_clientID, kinect_handle, pose_on_path);

                vrep_path::_percent_of_path += vrep_path::_path_increment;
                vrep_utils::step_sim();
            }
        }
    } catch (char *msg) {
        vrep_utils::stop_sim();
        std::cout << msg << std::endl;
    }

    return 0;
}