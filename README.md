# odmetry_lab
## test description : wheel odometry vs imu(angular Vel) + wheel(linear Vel) odometry accuracy test.

after donation robot, wheel odometry so weak about slip. 
especially, slip about rotation was so fatal.

in this case, I'll compare with wheel odom and imu + wheel odometry 

i checked imu acceleration have so much drift 
so, in my case, imu only correct orientation information (wheel linear velocity + imu angular velocity)

and IMU orientation have a little dritf bcuz graivity (In my opinion..)

so, if IMU have a little drivt error , took only wheel odometry !

## experiment result

 imu(angular Vel) + wheel(linear Vel) odometry much better than only wheel odom.
 
 nevertheless, slip due to linear vel ,yet, is weak.

 next time, i wanna check imu + wheel odom sensor fusion accuracy 
