
#include <pcl/filters/passthrough.h>
#include <pcl_ros/transforms.h>

#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

#include <cmath>

#include "pcl_passthrough.h"

PassThroughFilter::PassThroughFilter(ros::NodeHandle& nh):private_nh_(nh){
}

PassThroughFilter::~PassThroughFilter(){
}

void PassThroughFilter::RosInit(){

    vel_sub_           = private_nh_.subscribe("/velodyne_points", 1, &PassThroughFilter::CloudCallback, this);
    imu_sub_           = private_nh_.subscribe("/vehicle/imu/data_raw", 1, &PassThroughFilter::ImuCallback, this);
    points_pub_        = private_nh_.advertise<visualization_msgs::Marker>("point_marker", 10);
    line_list_pub_     = private_nh_.advertise<visualization_msgs::Marker>("line_list_marker", 10);
    line_strip_pub_    = private_nh_.advertise<visualization_msgs::Marker>("line_strip_marker", 10);
    ds_pub_            = private_nh_.advertise<sensor_msgs::PointCloud2>("downsampled_points", 10);
}

void PassThroughFilter::ImuCallback(const sensor_msgs::ImuConstPtr& msg){

}

void PassThroughFilter::CloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg){

    pcl::PointCloud<pcl::PointXYZI>::Ptr input_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZI>);

    pcl::fromROSMsg(*msg, *input_cloud);
    FilterCloud(input_cloud, filtered_cloud);
    PublishDownsampledPoints(filtered_cloud);
}

void PassThroughFilter::FilterCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr& input_cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr& filtered_cloud){

    pcl::PassThrough<pcl::PointXYZI> pass;
    pass.setInputCloud(input_cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.0, 1.0);
    pass.filter(*filtered_cloud);
}

void PassThroughFilter::PublishDownsampledPoints(pcl::PointCloud<pcl::PointXYZI>::Ptr &ds_points){

    sensor_msgs::PointCloud2 downsamped_cloud;
    pcl::toROSMsg(*ds_points, downsamped_cloud);
    ds_pub_.publish(downsamped_cloud);
}

void PassThroughFilter::PublishMarker(){
    visualization_msgs::Marker points, line_strip, line_list;
    
    //Update header.
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "velodyne";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;

    //Assign ID; this ID along with namespace creates a unique id.
    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;

    //Select type of the marker to be used.
    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
    line_list.type = visualization_msgs::Marker::LINE_LIST;

    //Scale
    points.scale.x = 0.2;
    points.scale.y = 0.2;
    line_strip.scale.x = 0.1;
    line_list.scale.x = 0.1;

    //Color
    points.color.g = 1.0f;
    points.color.a = 1.0;

    line_strip.color.b = 1.0f;
    line_strip.color.a = 1.0;

    //Create a helix
    for(uint32_t i = 0; i < 100; ++i){
        float y = 5 * sin(f + i/100.0f * 2 * M_PI);
        float z = 5 * cos(f + i/100.0f * 2 * M_PI);

        geometry_msgs::Point p;
        p.x = (int32_t)i - 50;
        p.y = y;
        p.z = z;

        points.points.push_back(p);
        line_strip.points.push_back(p);

        line_list.points.push_back(p);
        p.z += 1;
        line_list.points.push_back(p);
    }
    points_pub_.publish(points);
    line_strip_pub_.publish(line_strip);
    line_list_pub_.publish(line_list);
}

void PassThroughFilter::Run(){

    ros::spin();
}
