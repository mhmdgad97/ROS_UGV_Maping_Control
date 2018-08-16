/********************************************************************************************************
*                                        cloud_pup.cpp                                                  *
*********************************************************************************************************
*this is just a demo for publishing a point cloud so it can be viewd on rviz                            *
*to do: make this node like basic_shapes.cpp node that supscribe to topic contains mines location then  *
*publish point cloud with those locations in realtime                                                   *
********************************************************************************************************/
#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

int main(int argc, char** argv)
{
  ros::init (argc, argv, "pub_pcl");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<PointCloud> ("points2", 100);
  ros::Publisher pubDn = nh.advertise<PointCloud> ("points22", 100);
 int i; //just counter
  PointCloud::Ptr msg (new PointCloud);
  PointCloud::Ptr msgDn (new PointCloud);
  msg->header.frame_id = "/my_frame";
  msgDn->header.frame_id = "/my_frame";
  //msg->height = 
  //msg->width = 1;
  msg->points.push_back (pcl::PointXYZ(1.0, 2.0, 3.0));
  msgDn->points.push_back (pcl::PointXYZ(1.0, 2.0, 3.0));
//  msg->points.push_back (pcl::PointXYZ(1.0, 3.0, 3.0));

  ros::Rate loop_rate(5);
  while (nh.ok())
  {
if(i<1000000){
    msg->points.push_back (pcl::PointXYZ(i*0.002+1.0, 2.0, 3.0));
    msgDn->points.push_back (pcl::PointXYZ(i*0.002+1.0, 2.0, -3.0));
	i++;
}
    pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
    pcl_conversions::toPCL(ros::Time::now(), msgDn->header.stamp);
    pub.publish (msg);
    pubDn.publish (msgDn);
    ros::spinOnce ();
    loop_rate.sleep ();
  }
}
