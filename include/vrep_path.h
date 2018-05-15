//
// Created by kganguly on 5/15/18.
//

#pragma once

#include<string>
#include <iostream>
#include "vrep_utils.h"

extern "C" {
#include "extApi.h"
#include "extApiPlatform.h"
}

namespace vrep_path {
    float _percent_of_path;
    std::string _path_name;
    std::string _path_function;
    int _path_handle;
    int _count_floats_from_server;
    float *_floats_from_server;

    std::vector<float> fetch_path_data_from_relative_position();
}