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
            vrep_path::_percent_of_path = 0.0;
            vrep_path::_path_increment = 1e-2;

            int kinect_handle = vrep_utils::fetch_handle("kinect");

            while (simxGetConnectionId(vrep_utils::_clientID) != -1) {
                std::vector<float> pose_on_path = vrep_path::fetch_path_data_from_relative_position(
                        vrep_utils::_clientID);
                vrep_path::move_object_on_path(vrep_utils::_clientID, kinect_handle, pose_on_path,
                                               vrep_utils::_isStreamingInitialized);


                if (vrep_path::_percent_of_path < 1.0) {
                    vrep_path::_percent_of_path += vrep_path::_path_increment;
                } else {
                    vrep_path::_percent_of_path -= vrep_path::_path_increment;
                }

                vrep_utils::_isStreamingInitialized = true;
                vrep_utils::step_sim();
            }
        }
    } catch (char *msg) {
        vrep_utils::stop_sim();
        std::cout << msg << std::endl;
    }

    return 0;
}