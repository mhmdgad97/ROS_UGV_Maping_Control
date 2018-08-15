#include <ros.h>
#include <std_msgs/String.h>
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2, 3);

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup()
{
//  mySerial.begin(9600);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{



    String a = "20200450";
    str_msg.data = a.c_str();
    chatter.publish( &str_msg );    
  

  
  nh.spinOnce();
  delay(100);
}
