
#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/transforms.h>

#include "pcl_passthrough.h"

PassThroughFilter::PassThroughFilter(ros::NodeHandle& nh):nh_(nh){
}

void PassThroughFilter::RosInit(){
    nh_.subscribe("/velodyne_points", 10, &PassThroughFilter::CloudCallback, this);
}

void PassThroughFilter::CloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg){

}
