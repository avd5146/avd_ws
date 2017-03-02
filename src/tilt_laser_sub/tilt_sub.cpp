#include <ros/ros.h>
#include "tf/transform_listener.h"
#include "sensor_msgs/PointCloud.h"
#include "tf/message_filter.h"
#include "message_filters/subscriber.h"
#include "laser_geometry/laser_geometry.h"
void poseMessageReceived( const turtlesim::Pose& msg)
{
	ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "range is "<< msg.ranges);
}
int main(int argc, char **argv)
{
	ros::init(argc,argv,"subscribe_to_pose");
	ros::NodeHandle nh;
	ros::Subscriber sub=nh.subscribe("/tilt_scan",1000,&poseMessageReceived);
	ros::spin();
}
