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
you only need to do this once fore every Arduino port

### Install ros_lib into the Arduino Environment

this creates ros_lib, which must be copied into the Arduino build environment to enable Arduino programs to interact with ROS.


replace <sketchbook> with the directory where the Linux Arduino environment saves your sketches (usually at home)
```
cd <sketchbook>/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py
```
After restarting your IDE, you should see ros_lib listed under examples:

## Running the tests

to be written
### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Contributing

Please read [CONTRIBUTING.md]() for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/mhmdgad97/ROS_UGV_Maping_Control/tags). 

## Authors

* **mohamed Gad** - *Initial work* - [mhmdgad97](https://github.com/mhmdgad97)

See also the list of [contributors](https://github.com/mhmdgad97/ROS_UGV_Maping_Control/contributors) who participated in this project.

## License

See the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
