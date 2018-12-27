#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block PID_ros/Subscribe
extern SimulinkSubscriber<dbw_mkz_msgs::SteeringReport, SL_Bus_PID_ros_dbw_mkz_msgs_SteeringReport> Sub_PID_ros_191;

// For Block PID_ros/Subscribe1
extern SimulinkSubscriber<controller::TrackingInfo, SL_Bus_PID_ros_controller_TrackingInfo> Sub_PID_ros_174;

// For Block PID_ros/Enabled Subsystem1/Publish
extern SimulinkPublisher<dbw_mkz_msgs::SteeringCmd, SL_Bus_PID_ros_dbw_mkz_msgs_SteeringCmd> Pub_PID_ros_152;

// For Block PID_ros/Tracking Received/Publish
extern SimulinkPublisher<controller::TrackingInfo, SL_Bus_PID_ros_controller_TrackingInfo> Pub_PID_ros_158;

void slros_node_init(int argc, char** argv);

#endif
