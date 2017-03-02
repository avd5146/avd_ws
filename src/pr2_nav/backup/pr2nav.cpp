#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "publish_velocity");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("base_controller/command", 10000); // turtle1/cmd_vel to base_controller/command
	srand(time(0));
	ros::Rate rate(50);
	int a=0;
	geometry_msgs::Twist msg;
	while(ros::ok())
	{
		
		{
		msg.linear.x = 10;
		while(a <= 500)
		{
			//msg.linear.x = 0;
			msg.angular.z=10; //Must be [2,4] for 90 degree turn
			a++;
		}
		//else
		//msg.angular.z=1;
		pub.publish(msg);
		ROS_INFO_STREAM( "Sending random velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);
		rate.sleep();
		}
		a=0;
	}
}
