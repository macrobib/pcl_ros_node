#ifndef CONFIG_MANAGER_H_
#define CONFIG_MANGER_H_

#include <ros/ros.h>
#include <uWS/uWS.h>
#include <unordered_map>
#include <thread>
#include <algorithm>
#include <mutex>
#include <string>

#include "ros_config_structs.h"


using namespace uWS;

class ConnectionManager{
    
    std::thread event_handler_;
    std::mutex data_mutex_;
    std::string url_;
    uWS::Hub h_;
    std::unordered_map<int32_t, ros::Publisher*> publishers_;
    

    ros::Publisher pub1_, pub2_, pub3_, pub4_, pub5_;
    ros::NodeHandle nh_;

    std::string pass_topic_, voxel_topic_, stat_topic_, proj_topic_, cond_outlier_topic_, rad_outlier_topic_, icp_topic_, ransac_topic_, ndt_topic_;

    void HandlePassthroughParam(struct PassthroughArgs& arg);
    void HandleVoxelFilterParam(struct VoxelFilterArgs& arg);
    void HandleStatOutlierParam(struct StatOutlierArgs& arg);
    void HandleParamProjection(struct  ParamProjArgs& arg);
    void HandleCondOutlierParam(struct CondOutlierArgs& arg);
    void HandleRadOutlierParam(struct  RadOutlierArgs& arg);
    void HandleIcpParam(struct ICPArgs& arg);
    void HandleRansacParam(struct RansacArgs& arg);
    void HandleNdtParam(struct NdtArgs& arg);

public:
    ConnectionManager(std::string url, ros::NodeHandle& nh);
    ~ConnectionManager();
    void InitPublishers();
    void ThreadCallback();
    void ReadActiveData(char* data);
    void StartServer();
};

#endif /*CONFIG_MANAGER_H*/
