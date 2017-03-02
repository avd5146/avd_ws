#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	ros::init(argc, argv, "publish_velocity");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("base_controller/command", 1000); // turtle1/cmd_vel to base_controller/command
	srand(time(0));
	ros::Rate rate(2);
	int a=0;
	geometry_msgs::Twist msg;
	while(ros::ok())
	{
		
		{
		msg.linear.x = 1;
		if(a%5 == 0)
		{
		msg.angular.z=4; //Must be [2,4] for 90 degree turn
		}
		else
		msg.angular.z=0;
		pub.publish(msg);
		ROS_INFO_STREAM( "Sending␣random␣velocity␣command:"<<"␣linear="<<msg.linear.x<<"␣angular="<<msg.angular.z);
		rate.sleep();
		}
		a++;
	}
}
