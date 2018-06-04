#include <ros/ros.h>
#include <iostream>
#include "pcl_voxel_filtering.h"


int main(int argc, char* argv[]){

    ros::init(argc, argv, "voxel");
    ros::NodeHandle nh_("~");
 
    PclVoxelFilter pvf(nh_);
    ros::spin();
    
    return EXIT_SUCCESS;
}
