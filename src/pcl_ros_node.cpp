#include <iostream>
#include <ros/ros.h>
#include "pcl_ros_node.h"

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

int main(int argc, char* argv[]){

    int32_t param_impl;
    ros::init();
    ros::NodeHandle nh_;

    nh_.param("impl_option", param_impl, 0);

    switch(param_impl){
        case ePASSTHROUGH:
            ps_filter = PassThroughFilter(nh_);
            break;

        default:
            break;
    }
    ros::spin();
}
