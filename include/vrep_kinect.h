//
// Created by kganguly on 4/6/18.
//
#pragma once

#include <iostream>
#include "cilantro/image_viewer.hpp"
#include "cilantro/visualizer.hpp"
#include "cilantro/point_cloud.hpp"
#include "cilantro/image_point_cloud_conversions.hpp"

extern "C" {
#include "extApi.h"
#include "extApiPlatform.h"
}
namespace vrep_kinect {
    void init_kinect_rgb(int &client_id, int *resolution, pangolin::TypedImage &rgb_img, int &rgb_sensor_handle);

    void init_kinect_depth(int &client_id, int *resolution, pangolin::TypedImage &depth_img, int &depth_sensor_handle);

    void fetch_rgb(int &client_id, int *resolution, pangolin::TypedImage &rgb_img, int &rgb_sensor_handle);

    void fetch_depth(int &client_id, int *resolution, pangolin::TypedImage &depth_img, int &depth_sensor_handle);
}
