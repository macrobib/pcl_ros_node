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

struct CommonMessage
{
    MessageType type;
    union payload
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
    };
};

#endif /*ROS_CONFIG_STRUCT_*/
