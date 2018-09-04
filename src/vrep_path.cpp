//
// Created by kganguly on 5/15/18.
//


#include "vrep_path.h"

std::vector<float>
vrep_path::fetch_object_pose_xyzeuler(int &clientID, int &object_handle, std::map<int, bool> &isStreamingInitialized) {
    float tmp_orientation[3] = {0};
    int res = simxGetObjectOrientation(clientID, object_handle, -1, tmp_orientation,
                                       isStreamingInitialized[object_handle] == false ? simx_opmode_streaming
                                                                                      : simx_opmode_buffer);
    isStreamingInitialized[object_handle] = true;

    std::vector<float> curr_orientation_floats(tmp_orientation, tmp_orientation + 3);
    return curr_orientation_floats;
}

std::vector<float> vrep_path::fetch_path_data_from_relative_position(int &clientID) {
    simxCallScriptFunction(clientID, vrep_path::_path_name.c_str(), sim_scripttype_childscript,
                           vrep_path::_path_function.c_str(),
                           1, &vrep_path::_path_handle,                   // input int count, input int data
                           1, &vrep_path::_percent_of_path,               // input float count, input float data
                           0, NULL,                           // input string count, input string data
                           0, NULL,                           // input buffer size, input buffer data
                           NULL, NULL,                        // output int count, output int data
                           &vrep_path::_count_floats_from_server,
                           &vrep_path::_floats_from_server, // output float count, output float data
                           NULL, NULL,                        // output string count, output string data
                           NULL, NULL,                        // output buffer count, output buffer data
                           simx_opmode_blocking);

    std::vector<float> vrep_vals(vrep_path::_floats_from_server,
                                 vrep_path::_floats_from_server + vrep_path::_count_floats_from_server);
    return vrep_vals;
}

void
vrep_path::move_object_on_path(int &clientID, int &object1_handle,
                               std::vector<float> &object1_pose,
                               std::map<int, bool> &isStreamingInitialized) {
    simxSetObjectPosition(clientID, object1_handle, -1, object1_pose.data(), simx_opmode_oneshot);
//    int res = simxSetObjectOrientation(clientID, object1_handle, -1, lookAt_camera_world.data(), simx_opmode_oneshot);

}



Eigen::Matrix3f vrep_path::rotation_matrix_from_euler(Eigen::Vector3f euler) {
    float a = euler(0);
    float b = euler(1);
    float g = euler(2);

    Eigen::Matrix3f rot;
    rot = Eigen::AngleAxisf(a, Eigen::Vector3f::UnitX()) *
          Eigen::AngleAxisf(b, Eigen::Vector3f::UnitY()) *
          Eigen::AngleAxisf(g, Eigen::Vector3f::UnitZ());

    return rot;
}