#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <sstream>
#include <geometry_msgs/Pose.h>
#include <math.h>       /* sin */

#define PI 3.14159265
#define encPulseRatio 0.001

geometry_msgs::Pose posToPublish;
bool posflag = false;
bool mineflag = false;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std::string str= msg->data;
  
  std::stringstream geekenc(str.substr(1,3));
  std::stringstream geekang(str.substr(4,3));
  int enc,ang,sign;
  geekenc >> enc;
  geekang >> ang;
  if(str[0] == '2'){
     sign = 1;
  }
  else if(str[0] == '1'){
    sign = -1;
  }
  else{
  ROS_WARN("I h=jhiuu");
  }

  posToPublish.position.x+=sign*enc*encPulseRatio*sin(ang*PI/180);
  posToPublish.position.y+=sign*enc*encPulseRatio*cos(ang*PI/180);
  posToPublish.orientation.x = cos(ang*PI/180);
  posToPublish.orientation.y = sin(ang*PI/180);

  posflag = true;

  ROS_INFO("pulses [%i]", enc);
  ROS_INFO("angle [%i]", ang);

  switch(str[7]) {
       case '1':
         //ROS_INFO("I h=jhiuu");

       
        break;
      case '2':
        //ROS_INFO("I h=jhiuu");

      
        break;
      case '3':

        break;
      case '4':

        break;
      default:
        break;
   }
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pospublisher");
  ros::NodeHandle n;
  ros::Rate r(5);
  ros::Publisher RobPos = n.advertise<geometry_msgs::Pose>("RobPos", 100);
  ros::Subscriber sub = n.subscribe("/chatter", 100, chatterCallback);

  while (ros::ok())
  {

    // Publish the marker
    while (RobPos.getNumSubscribers() < 1)
    {
       if (!ros::ok())
       {
         return 0;
       }
       ROS_WARN_ONCE("Please create a subscriber to the pospub");
       sleep(1);
    }

    if(posflag){
       RobPos.publish(posToPublish);
       posflag = false;
    }

    if(mineflag){

       mineflag = false;
    }

    ros::spinOnce ();
    r.sleep();


    //chatter_pub.publish(msg);

    //ros::spinOnce();

    //loop_rate.sleep();
    //++count;
  }



  return 0;
}
