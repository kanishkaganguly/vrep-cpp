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
vrep_path::move_object_on_path_lookat(int &clientID, int &object1_handle, int &object2_handle,
                                      std::vector<float> &object1_pose,
                                      std::map<int, bool> &isStreamingInitialized) {
    // Object1 looks at Object2
    std::vector<float> current_camera_pose = vrep_path::fetch_object_pose_xyzeuler(clientID, object1_handle,
                                                                                   isStreamingInitialized);
    std::vector<float> current_worlditem_pose = vrep_path::fetch_object_pose_xyzeuler(clientID, object2_handle,
                                                                                      isStreamingInitialized);

    Eigen::Vector3f lookAt_camera_world = vrep_path::compute_lookat_vector(current_camera_pose, current_worlditem_pose);

//    simxSetObjectPosition(clientID, object1_handle, -1, object1_pose.data(), simx_opmode_oneshot);
    int res = simxSetObjectOrientation(clientID, object1_handle, -1, lookAt_camera_world.data(), simx_opmode_oneshot);

}

Eigen::Vector3f
vrep_path::compute_lookat_vector(std::vector<float> pose_data_from, std::vector<float> pose_data_to) {

    Eigen::Vector3f from_trans(pose_data_from[0], pose_data_from[1], pose_data_from[2]);
    Eigen::Vector3f to_trans(pose_data_to[0], pose_data_to[1], pose_data_to[2]);
    Eigen::Vector3f from_rot_euler(pose_data_from[3], pose_data_from[4], pose_data_from[5]);
    Eigen::Vector3f to_rot_euler(pose_data_to[3], pose_data_to[4], pose_data_to[5]);

    Eigen::Matrix3f from_rot = vrep_path::rotation_matrix_from_euler(from_rot_euler);
    Eigen::Matrix3f to_rot = vrep_path::rotation_matrix_from_euler(to_rot_euler);

    Eigen::Vector3f forward = (from_trans - to_trans).normalized();
    Eigen::Vector3f tmp = Eigen::Vector3f::UnitZ();
    Eigen::Vector3f right = (tmp.normalized()).cross(forward);
    Eigen::Vector3f up = forward.cross(right);

//    Eigen::Vector3f y_vec = (from_trans - to_trans).normalized();
//    Eigen::Vector3f z_vec = Eigen::Vector3f::UnitZ();
//    z_vec = (z_vec - z_vec.dot(y_vec) * y_vec).normalized();
//    Eigen::Vector3f x_vec = z_vec.cross(y_vec);

    // lookAt Vector
    Eigen::Matrix3f lookAt;
    lookAt.row(0) = right;
    lookAt.row(1) = up;
    lookAt.row(2) = forward;

    return lookAt.eulerAngles(0, 1, 2);
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