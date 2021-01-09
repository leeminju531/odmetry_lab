
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

double x = 0.0;
double y = 0.0;
double th = 0.0;
double vx;
double vy = 0;
double vth;
bool odom_cal = false;

void wheel_Info(const geometry_msgs::Twist &msg){
    vx = msg.linear.x;
    vth = msg.angular.z;
    odom_cal = true;
}



int main(int argc, char **argv){
    ros::init(argc, argv, "wheel_odom_node");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("lab/vel", 10, wheel_Info);
    tf2_ros::TransformBroadcaster br;

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    while (n.ok()){

        ros::spinOnce(); // check for incoming messages

        
        if (odom_cal) {
        	odom_cal = false;
            current_time = ros::Time::now();

        	double dt = (current_time - last_time).toSec();
            double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
            double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
            double delta_th = vth * dt;

            x += delta_x;
            y += delta_y;
            th += delta_th;

            geometry_msgs::TransformStamped transformStamped; 

			transformStamped.header.stamp = ros::Time::now();//we need to give the transform being published a timestamp, in this case current time
			transformStamped.header.frame_id = "odom";
			transformStamped.child_frame_id = "base_footprint";
			transformStamped.transform.translation.x = x;
			transformStamped.transform.translation.y = y;
			transformStamped.transform.translation.z = 0; 
			
			tf2::Quaternion q;
			q.setRPY(0,0,th);
			transformStamped.transform.rotation.x = q.x();
			transformStamped.transform.rotation.y = q.y();
			transformStamped.transform.rotation.z = q.z();
			transformStamped.transform.rotation.w = q.w();

			br.sendTransform(transformStamped); // this is where real work is done

			last_time = current_time;
            
        }


    }



    return 0;
}