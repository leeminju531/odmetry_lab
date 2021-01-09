#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


int Control_cycle = 10; // 10hz

int main(int argc, char **argv){

	ros::init(argc, argv, "temporary_motor_node");
  	ros::NodeHandle nh;

//  	ros::Subscriber temp_vel_sub = nh.subscribe("/donationTF/cmd",10,tfVelCallback);
  	ros::Publisher temp_vel_pub = nh.advertise <geometry_msgs::Twist>("lab/vel",10);

  	geometry_msgs::Twist temp_odom;
  	ros::Rate loop_rate(Control_cycle);

  	while (nh.ok()){



  		temp_odom.linear.x = 0.1;
  		temp_odom.angular.z = 0;

  		temp_vel_pub.publish(temp_odom);



  		loop_rate.sleep();
  	}




}