#ifndef ROS_CONFIG_STRUCTS_
#define ROS_CONFIG_STRUCTS_


enum MessageType
{
    ePASSTHROUGH, //0
    eVOXELFILTER,
    eSTATOUTLIER,
    ePARAMPROJECTION,
    eCONDOUTLIER,
    eRADOUTLIER,
    eICP,
    eRANSAC,
    eNDT //8
};


struct PassthroughArgs
{
    double min_z;
    double max_z;
};

struct VoxelFilterArgs
{

};

struct StatOutlierArgs
{

};

struct ParamProjArgs
{

};

struct CondOutlierArgs
{

};

struct RadOutlierArgs
{

};

struct ICPArgs
{

};

struct RansacArgs
{

};

struct NdtArgs
{

};

typedef union payload_data
{
    struct PassthroughArgs ps;
    struct VoxelFilterArgs vf;
    struct StatOutlierArgs so;
    struct ParamProjArgs pp;
    struct CondOutlierArgs co;
    struct RadOutlierArgs ro;
    struct ICPArgs icp;
    struct RansacArgs ransac;
    struct NdtArgs ndt;
}payload;

struct CommonMessage
{
    MessageType type;
    payload data;
};

#endif /*ROS_CONFIG_STRUCT_*/
