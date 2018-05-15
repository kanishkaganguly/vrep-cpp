//
// Created by kganguly on 5/15/18.
//

#include <vector>
#include "vrep_path.h"


std::vector<float> vrep_path::fetch_path_data_from_relative_position() {
    simxCallScriptFunction(vrep_utils::_clientID, vrep_path::_path_name.c_str(), sim_scripttype_childscript,
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