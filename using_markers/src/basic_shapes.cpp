#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/Int32.h>

float px=3.0f;
float py=1.0f;
float ox=0.0f;
float oy=1.0f;
bool flag = false;


void posCallback(const geometry_msgs::Pose::ConstPtr& recmsg)
{
  px= recmsg->position.x;
  py= recmsg->position.y;
  ox= recmsg->orientation.x;
  oy= recmsg->orientation.y;
  flag = true;

}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(5);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber sub = n.subscribe("RobPos", 100, posCallback);

  // Set our initial shape type to be a ARROW
  uint32_t shape = visualization_msgs::Marker::CUBE;


  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/my_frame";
    marker.header.stamp = ros::Time::now();
    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;
    // Set the marker type.
    marker.type = shape;
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = px;
    marker.pose.position.y = py;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = ox;
    marker.pose.orientation.y = oy;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 0.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    if(flag){
    marker_pub.publish(marker);  
    ROS_INFO("published marker");
    flag = false;
    }

    ros::spinOnce ();
    r.sleep();
  }
}
