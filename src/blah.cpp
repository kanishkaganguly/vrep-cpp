//
// Created by kganguly on 4/2/18.
//

#include "blah.h"

int main(int argc, char *argv[]) {
    int rgb_resolution[2] = {640, 480};
    int depth_resolution[2] = {640, 480};
    int rgb_handle = -1;
    int depth_handle = -1;
    pangolin::TypedImage rgb_img(rgb_resolution[0], rgb_resolution[1], pangolin::PixelFormatFromString("RGB24"));
    pangolin::TypedImage depth_img(depth_resolution[0], depth_resolution[1],
                                   pangolin::PixelFormatFromString("GRAY16LE"));

    pangolin::CreateWindowAndBind("VREP Window", 1280, 480);
    pangolin::Display("multi").SetBounds(0.0, 1.0, 0.0, 1.0).SetLayout(pangolin::LayoutEqual).AddDisplay(
            pangolin::Display("disp1")).AddDisplay(pangolin::Display("disp2"));

    cilantro::ImageViewer rgbv("VREP Window", "disp1");
    cilantro::ImageViewer depthv("VREP Window", "disp2");

    cilantro::Visualizer viz;

    vrep_utils::launch_vrep();
    vrep_utils::setup_vrep_remote();

    try {
        if (simxGetConnectionId(vrep_utils::_clientID) != -1) {
            vrep_utils::load_scene();
            vrep_utils::start_sim();
            rgb_handle = vrep_utils::fetch_handle("kinect_rgb");
            depth_handle = vrep_utils::fetch_handle("kinect_depth");

            vrep_kinect::init_kinect_rgb(vrep_utils::_clientID, rgb_resolution, rgb_img, rgb_handle);
            vrep_kinect::init_kinect_depth(vrep_utils::_clientID, depth_resolution, depth_img, depth_handle);
            while (simxGetConnectionId(vrep_utils::_clientID) != -1 && !pangolin::ShouldQuit()) {
                vrep_kinect::fetch_rgb(vrep_utils::_clientID, rgb_resolution, rgb_img, rgb_handle);
                vrep_kinect::fetch_depth(vrep_utils::_clientID, depth_resolution, depth_img, depth_handle);

                rgbv.clearRenderArea().setImage(rgb_img.ptr, rgb_resolution[0], rgb_resolution[1], "RGB24").render();
                depthv.setImage(depth_img.ptr, depth_resolution[0], depth_resolution[1],
                                "GRAY16LE").render();
                pangolin::FinishFrame();

                Eigen::Matrix3f K;
                K << 528, 0, 320, 0, 528, 240, 0, 0, 1;
                cilantro::PointCloud3f cloud;
                cloud.template fromRGBDImages<unsigned short>(rgb_img.ptr, (unsigned short *) depth_img.ptr,
                                                              rgb_resolution[0],
                                                              rgb_resolution[1], K, false,
                                                              cilantro::DepthValueConverter<unsigned short, float>(
                                                                      1000.0f));
                vrep_utils::step_sim();
                viz.addPointCloud("le_cloud", cloud).spinOnce();
            }
        } else {
            std::cout << "Failed to connect to V-REP" << std::endl;
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }
    vrep_utils::exit_vrep();
    std::cout << "Exiting V-REP" << std::endl;
    return 0;
}