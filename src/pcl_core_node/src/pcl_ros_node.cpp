#include <iostream>
#include <ros/ros.h>
#include "pcl_ros_node.h"
#include "pcl_passthrough.h"

enum version:int32_t{
    ePASSTHROUGH,
    eVOXEL,
    eSMOOTHING,
    eDOWNSAMPLE,
    eUPSAMPLE,
    eRANSAC,
    eICP,
    eNDT
};

void pointCallback(const sensor_msgs::PointCloud2ConstPtr& msg){

}

int main(int argc, char* argv[]){

    int32_t param_impl = 0;
    ros::init(argc, argv, "pcl_ros_node");

    ros::NodeHandle nh_("~");
    PassThroughFilter ps_filter(nh_);
    /* nh_.subscribe("/velodyne_points", 1, &pointCallback); */

    switch(param_impl){
        case ePASSTHROUGH:
            {
                ps_filter.RosInit();
            }
            break;
        default:
            break;
    }

    ros::spin();
}
