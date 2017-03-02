#include "ros/ros.h"
#include "pr2_common_action_msgs/TuckArmsActionGoal.h"					// for tuckarms

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Pr2TuckBoth_pub");
	ros::NodeHandle n;
	ros::Publisher Tucker_pub = n.advertise<pr2_common_action_msgs::TuckArmsActionGoal>("tuck_arms/goal", 5);
	
	usleep(1*1000*1000);
	
	pr2_common_action_msgs::TuckArmsActionGoal Tuck;
	printf("Tucking both arms...\n");
	Tuck.header.stamp = ros::Time::now();
	Tuck.goal_id.stamp = ros::Time::now();
	Tuck.goal.tuck_left = true;
	Tuck.goal.tuck_right = true;
	Tucker_pub.publish(Tuck);
	
	usleep(1*1000*1000);

	return 0;
}
