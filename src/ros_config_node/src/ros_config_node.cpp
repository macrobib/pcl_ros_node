#include <ros/ros.h>
#include "ros_config_manager.h"

void signal_handler(int signal){
    ROS_INFO_STREAM("Exiting ROS node.");
    ros::shutdown();
}


int main(int argc, char* argv[]){

    ros::init(argc, argv, "ros_config_node");
    ros::NodeHandle node_private("~");
    ConnectionManager conn_man("//127.0.0.1:6000", node_private);
    std::signal(SIGINT, signal_handler);
    conn_man.StartServer();
    ros::spin();

    return 0;
}
