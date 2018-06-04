#include <ros/ros.h>
#include "ros_config_manager.h"

int main(int argc, char* argv[]){

    ros::init(argc, argv, "ros_config_node");
    ros::NodeHandle node_private("~");
    ConnectionManager conn_man("//127.0.0.1:6000", node_private);
    ros::spin();

    return 0;
}
