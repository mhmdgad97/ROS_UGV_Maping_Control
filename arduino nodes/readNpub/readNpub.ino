#include <ros.h>
#include <std_msgs/String.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup()
{
  mySerial.begin(9600);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  if (mySerial.available()> 0 )
  {
    str_msg.data = mySerial.readString().c_str();
    chatter.publish( &str_msg );    
  }
  
  nh.spinOnce();
  delay(3);
}
