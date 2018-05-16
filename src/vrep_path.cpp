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


    simxSetObjectPosition(clientID, object1_handle, -1, object1_pose.data(), simx_opmode_oneshot);
    simxSetObjectOrientation(clientID, object1_handle, -1, lookAt_camera_world.data(), simx_opmode_oneshot);
}

Eigen::Matrix4f vrep_path::create_transformation_matrix_from_values(std::vector<float> position_euler_data) {
    float x = position_euler_data[0];
    float y = position_euler_data[1];
    float z = position_euler_data[2];
    float a = position_euler_data[3];
    float b = position_euler_data[4];
    float g = position_euler_data[5];

    Eigen::Matrix3f rot;
    rot = Eigen::AngleAxisf(a, Eigen::Vector3f::UnitX()) *
          Eigen::AngleAxisf(b, Eigen::Vector3f::UnitY()) *
          Eigen::AngleAxisf(g, Eigen::Vector3f::UnitZ());


    Eigen::Matrix4f transformation_matrix;
    transformation_matrix.setIdentity();
    transformation_matrix.topLeftCorner(3, 3) = rot;
    transformation_matrix.bottomLeftCorner(1, 3) = Eigen::Vector3f(x, y, z);

    return transformation_matrix;
}

Eigen::Vector3f
vrep_path::compute_lookat_vector(std::vector<float> pose_data_from, std::vector<float> pose_data_to) {
    Eigen::Matrix4f from_tf = vrep_path::create_transformation_matrix_from_values(pose_data_from);
    Eigen::Matrix4f to_tf = vrep_path::create_transformation_matrix_from_values(pose_data_to);

    Eigen::Vector3f y_vec = (to_tf.bottomLeftCorner(1, 3) - from_tf.bottomLeftCorner(1, 3)).normalized();
    Eigen::Vector3f z_vec = Eigen::Vector3f::UnitZ();
    z_vec = (z_vec - z_vec.dot(y_vec) * y_vec).normalized();
    Eigen::Vector3f x_vec = z_vec.cross(y_vec);

    // lookAt Vector
    Eigen::Matrix3f lookAt;
    lookAt.row(0) = x_vec;
    lookAt.row(1) = y_vec;
    lookAt.row(2) = z_vec;

    return lookAt.eulerAngles(0, 1, 2);
}