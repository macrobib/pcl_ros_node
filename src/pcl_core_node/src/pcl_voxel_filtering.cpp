#include "pcl_voxel_filtering.h"

#include <string>
#include <cmath>

PclVoxelFilter::PclVoxelFilter(ros::NodeHandle& nh):private_nh_(nh){
    InitTopics();
}

PclVoxelFilter::~PclVoxelFilter(){}

void PclVoxelFilter::InitTopics()
{
    std::string velodyne_topic;
    std::string filtered_topic;

    private_nh_.param<std::string>("velodyne_topic", velodyne_topic, "/velodyne_points");
    private_nh_.param<std::string>("filtered_topic", filtered_topic, "/filtered_points");
    
    cloud_sub_ = private_nh_.subscribe("/velodyne_points", 1, &PclVoxelFilter::CloudCallback, this);
    cloud_pub_ = private_nh_.advertise<sensor_msgs::PointCloud2>(filtered_topic, 1, true);
    ROS_INFO_STREAM("Completed subscription.."); 
}

void PclVoxelFilter::CloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg)
{
}

void PclVoxelFilter::VoxelFilter(pcl::PointCloud<pcl::PointXYZI>::Ptr& input, pcl::PointCloud<pcl::PointXYZI>::Ptr& output)
{
    
}
