#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "turtlebot_move_node");
  ros::NodeHandle nh;

  ros::Publisher pub =
      nh.advertise<geometry_msgs / Twist>("turtle_cmd_vel", 1000);
  ros::Rate loop_rate(2);

  geometry_msgs::Twist command_vel;
  command_vel.angular.z = 0.25;
  command_vel.linear.x = 0.5;

  while (ros::ok()) {
    pub.publish(command_vel);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
