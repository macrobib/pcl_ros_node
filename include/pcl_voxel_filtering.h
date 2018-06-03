#ifndef PCL_VOXEL_FILTERING_H_
#define PCL_VOXEL_FILTERING_H_
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Imu.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class PclVoxelFilter
{
    ros::NodeHandle private_nh_;
    ros::Publisher cloud_pub_;
    ros::Subscriber cloud_sub_;    

    void VoxelFilter(pcl::PointCloud<pcl::PointXYZI>::Ptr& input, pcl::PointCloud<pcl::PointXYZI>::Ptr& output);
    void InitTopics();

public:
    PclVoxelFilter(ros::NodeHandle& nh);
    ~PclVoxelFilter();
    void CloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg);
};


#endif /*PCL_VOXEL_FILTERING_H_*/
