//
// Created by kganguly on 4/6/18.
//

#include <string>
#include <iostream>
#include "vrep_kinect.h"


void
vrep_kinect::init_kinect_rgb(int &client_id, int *resolution, pangolin::TypedImage &rgb_img, int &rgb_sensor_handle) {
    unsigned char *rgb_img_flip;

    simxGetVisionSensorImage(client_id, rgb_sensor_handle, resolution, &rgb_img_flip, 0, simx_opmode_streaming);

    if (rgb_sensor_handle > -1) {
        std::cout << "Kinect RGB Initialized: " << rgb_sensor_handle << std::endl;
    } else {
        std::cout << "Kinect RGB Initialization Failed" << std::endl;
        exit(0);
    }
}

void vrep_kinect::init_kinect_depth(int &client_id, int *resolution, pangolin::TypedImage &depth_img,
                                    int &depth_sensor_handle) {
    float *depth_img_flip;

    simxGetVisionSensorDepthBuffer(client_id, depth_sensor_handle, resolution, &depth_img_flip, simx_opmode_streaming);
    if (depth_sensor_handle > -1) {
        std::cout << "Kinect Depth Initialized: " << depth_sensor_handle << std::endl;
    } else {
        std::cout << "Kinect Depth Initialization Failed" << std::endl;
        exit(0);
    }
}

void
vrep_kinect::fetch_rgb(int &client_id, int *resolution, pangolin::TypedImage &rgb_img, int &rgb_sensor_handle) {
    unsigned char *rgb_img_flip;

    if (simxGetVisionSensorImage(client_id, rgb_sensor_handle, resolution, &rgb_img_flip, 0, simx_opmode_buffer) ==
        simx_return_ok) {
        for (size_t i = 0; i < resolution[1]; i++) {
            std::memcpy(rgb_img.RowPtr(resolution[1] - i - 1),
                        rgb_img_flip + 3 * i * resolution[0] * sizeof(unsigned char),
                        3 * resolution[0] * sizeof(unsigned char));
        }
    }
}

void
vrep_kinect::fetch_depth(int &client_id, int *resolution, pangolin::TypedImage &depth_img, int &depth_sensor_handle) {
    float *depth_img_flip;

    if (simxGetVisionSensorDepthBuffer(client_id, depth_sensor_handle, resolution, &depth_img_flip,
                                       simx_opmode_buffer) == simx_error_noerror) {
        const float zNear = 0.01f;
        const float zFar = 3.5f;

        unsigned short *dst = (unsigned short *) depth_img.ptr;
        for (size_t i = 0; i < resolution[1]; i++) {
            for (size_t j = 0; j < resolution[0]; j++) {
                dst[i * resolution[0] + j] = (unsigned short) (
                        (zNear + depth_img_flip[resolution[0] * (resolution[1] - 1 - i) + j] * (zFar - zNear)) *
                        1000.0f);
                if (depth_img_flip[resolution[0] * (resolution[1] - 1 - i) + j] > 0.995f ||
                    depth_img_flip[resolution[0] * (resolution[1] - 1 - i) + j] < 0.005f) {
                    dst[i * resolution[0] + j] = 0;
                }
            }
        }
    }
}