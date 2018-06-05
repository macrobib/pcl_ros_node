#include "ros_config_manager.h"
#include <std_msgs/Float64MultiArray.h>

ConnectionManager::ConnectionManager(std::string url, ros::NodeHandle& nh):url_(url), nh_(nh), event_handler_()
{
    InitPublishers();
}

ConnectionManager::~ConnectionManager()
{
   event_handler_.join(); 
}

void ConnectionManager::StartServer()
{
    event_handler_ = std::thread(&ConnectionManager::ThreadCallback, this);
}

void ConnectionManager::ThreadCallback()
{
    h_.onMessage([this](uWS::WebSocket<uWS::CLIENT>*ws, char* message, size_t length, uWS::OpCode opCode){
                ROS_INFO_STREAM("Configuration message received.");  
                
            });
    h_.onDisconnection([](uWS::WebSocket<uWS::CLIENT> *ws, int code, char *message, size_t length){
                ROS_INFO_STREAM("Connection to the configuration gui lost, exiting.");
                return;
            });
    h_.connect("ws://127.0.0.1:7000", (void *) 10, {}, 60000);
    h_.run();
    ROS_INFO_STREAM("Exiting the event handler thread.");
}

void ConnectionManager::ReadActiveData()
{

}

void ConnectionManager::InitPublishers()
{
    nh_.param<std::string>("pass_topic", pass_topic_, "/passthrough_config" );
    nh_.param<std::string>("voxel_topic", voxel_topic_, "/voxel_config" );
    nh_.param<std::string>("stat_topic", stat_topic_, "/stat_config" );
    nh_.param<std::string>("proj_topic", pass_topic_, "/proj_config" );
    nh_.param<std::string>("cond_outlier_topic", pass_topic_, "/cond_outlier_config" );
    nh_.param<std::string>("rad_outlier_topic", pass_topic_, "/rad_outlier_config" );
    nh_.param<std::string>("icp_topic", pass_topic_, "/icp_config" );
    nh_.param<std::string>("ransac_topic", pass_topic_, "/ransac_config" );
    nh_.param<std::string>("ndt_topic", pass_topic_, "/ndt_config" );

    pub1_ = nh_.advertise<std_msgs::Float64MultiArray>(pass_topic_, 1, true );
    publishers_[ePASSTHROUGH] = &pub1_;  

}
