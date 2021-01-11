# odmetry_lab
## test description : [wheel odometry] vs [imu(angular Vel) + wheel(linear Vel) odometry] accuracy test.

after donation robot, i realized that wheel odometry so weak about slip. 
especially, slip at rotation was so fatal.

in this case, I'll compare with [wheel odom] and [imu + wheel odom] 

i checked imu acceleration have so much drift 

and IMU angular Velocity have a little dritf bcuz MEMS imu, graivity .. etc 

( IMU at my demo robot is MPU6050 very cheep , MEMS, and IMU hardware completely not fixed )

but, i checked  even though mpu6050, after calibration imu angle info fairly right

so, in my case, imu only correct angular Velocity information (wheel linear velocity + imu angular velocity)

and, if IMU have a little drift error , took only wheel odometry !

## experiment result

 imu(angular Vel) + wheel(linear Vel) odometry much better than only wheel odom.
 
 nevertheless, slip due to linear vel ,yet, is weak.

 next time, if i got a nice IMU sensor, i wanna check IMU + wheel odometry sensor fusion accuracy 
