# odmetry_lab
## test description : wheel odometry vs imu(angular Vel) + wheel(linear Vel) odometry accuracy test.

after donation robot, i realized wheel odometry so weak about slip. 
especially, slip about rotation was so fatal.

in this case, I'll compare with wheel odom and imu + wheel odometry 

i checked imu acceleration have so much drift 

and IMU angular Velocity have a little dritf bcuz MEMS imu, graivity .. etc 

( IMU at my demo robot is MPU6050 very cheep and MEMS, and IMU hardware complete not fixed )


so, in my case, imu only correct angular Velocity information (wheel linear velocity + imu angular velocity)

and, if IMU have a little drivt error , took only wheel odometry !

## experiment result

 imu(angular Vel) + wheel(linear Vel) odometry much better than only wheel odom.
 
 nevertheless, slip due to linear vel ,yet, is weak.

 next time, i wanna check imu + wheel odom sensor fusion accuracy 
