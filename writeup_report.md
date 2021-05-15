### Writeup/README

### 1. Thought process

-> I started with the general flow i.e. defined the different errors(p, i, d) and used them in order to calculate the total error based on the crosstrack error.
-> Initialized the pid controller with default values of gains i.e. Kp, Ki, Kd to somewhat closer to what was used during the lectures.
-> Then I tuned the hyper-parameters manually to that the car could drive without going off the track.
-> I even tried to implement twiddle algorithm in its separate class but could not succeed.
-> After this, I implemented another controller for speed so as to drive closer to the target speed.

After trying above steps, the car was able to drive autonomously on the track with a target speed of 30 mph and by tuning the hyperparameters manually.4
Note: I did some changes in CMakeLists.txt, main.cpp, PID.h so as to take into account the changes for throttle controller and twiddle.

### 2. The different P, I and D components in my implementation

In the context of crosstrack error,
-> P component - tries to provide steering angle proportional to CTE, this caused overshooting and even oscillations. This is an expected behaviour.
-> I component - this tries to provide a steering angle when we are going parallel to the desired trajectory. Effect is prominent when we have a drifting angle. This tried to maintain some steering angle based on the accumulated CTE over time, kind of provided stability and desired results as expected.
-> D component - provides steering angle proportional to the change in CTE i.e. damping term. This removes the oscillation behaviour caused by P controller. This is expected because as we move towards desired trajectory with greater angles, this will cause slowing down the change in steering angle and start steering in the opposite direction. 

### 3. Choosing the hyper-parameters

The hyperparameters for both the CTE and speed were choosen manually so that the car could drive autonomously. I tried twiddle algorithm also, but that did not work out. 

I started with P controller and could see the car was oscillating as expected. So, I tried to add the damping term i.e. D controller to reduce the oscillations of the car. Car was still not able to drive, so I added the I controller to make the correction in the steering angle. After this, the car was able to drive autonomously. After this, I added another class for velocity controller, and tuned the hyper-paramters in the same way as the previous controller.

Finally, the car was able to drive autonomously close to target speed on the track.