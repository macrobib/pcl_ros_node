#ifndef PCL_ROS_PASSTHROUGH_
#define PCL_ROS_PASSTHROUGH_

#include <ros/ros.h>
#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Imu.h>
#include <vector>


class PassThroughFilter{

    ros::NodeHandle nh_;
    ros::Publisher points_pub_;
    ros::Publisher line_strip_pub_;
    ros::Publisher line_list_pub_;
    ros::Publisher ds_pub_;
    float f = 0.0f;
    
    void FilterCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr& input_cloud,
            pcl::PointCloud<pcl::PointXYZI>::Ptr& filtered_cloud);
    void PublishMarker();
    void PublishDownsampledPoints(pcl::PointCloud<pcl::PointXYZI>::Ptr& ds_points);

public:
    PassThroughFilter(ros::NodeHandle& nh);
    ~PassThroughFilter();

    void CloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg);
    void ImuCallback(const sensor_msgs::ImuConstPtr &msg);
    void Run();
    void RosInit();
};

#endif /*PCL_ROS_PASSTHROUGH_*/
