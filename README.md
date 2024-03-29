# ROS_UGV_Maping_Control

ROS package that performs full control of UGV with a joystick and viewing the position of the UGV on RVIZ map, also the UGV scans for mines and their position is marked on the map.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes

### Prerequisites

you need to have ros kinetic installed
RVIZ
rosserial_arduino , and  rosserial libraries

### Install the Arduino Software (IDE) on Linux

you need to have Arduino IDE on Ubuntu so you can add ros_lib library easily
but you can use a windows version of Arduino IDE and add the libraries manually (hard)

to install Arduino IDE on ubuntu follow this [instructions](https://www.arduino.cc/en/Guide/Linux)

make sure that you gave permissions to edit Arduino serial ports (at the end of the install tutorial)
or use this command, but replace (0) after ACM with your Arduino serial port number
```
sudo chmod 666 /dev/ttyACM0
```
you only need to do this once for every Arduino port

### Install ros_lib into the Arduino Environment

this creates ros_lib, which must be copied into the Arduino build environment to enable Arduino programs to interact with ROS.


replace (sketchbook) with the directory where the Linux Arduino environment saves your sketches (usually at home)
```
cd <sketchbook>/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py
```
After restarting your IDE, you should see ros_lib listed under examples:

## Running the tests

to be written

## Authors

* **mohamed Gad** - *Initial work* - [mhmdgad97](https://github.com/mhmdgad97)

See also the list of [contributors](https://github.com/mhmdgad97/ROS_UGV_Maping_Control/contributors) who participated in this project.

## License

See the [LICENSE.md](LICENSE.md) file for details

## References
installing ros_lib [wiki.ros](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup)
## Acknowledgments
