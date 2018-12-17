#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <cstdlib>

/*void set_frequenza(const std_msgs::Float64& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}*/

int main(int argc, char **argv)
{
  //int c=0;
  ros::init(argc, argv, "set");

  if (argc != 2)
  {
    ROS_INFO("Inserire frequenza");
    return 1;
  }

  ROS_INFO("START");
  
  ros::NodeHandle n;
  ros::Rate oneSecond(1);

  
  std_msgs::Float64 freq;

  //bool var=true;
  freq.data=atof(argv[1]);
  //set.publish(freq);
  while(ros::ok())
  {
    ros::Publisher set = n.advertise<std_msgs::Float64>("set_freq", 1000);
    oneSecond.sleep();
    //ros::Rate loop_rate(1);

    //freq.data=freq.data*10;*/

    //ROS_INFO("pre %lf",freq.data);
    
    set.publish(freq);
    oneSecond.sleep();
    //set.shutdown();
    
    ros::shutdown();
    //var=false;
    //c++;
    //ros::spin();
    //ros::spinOnce();
    
    //loop_rate.sleep();
  }

  ROS_INFO("fine %lf",freq.data);
  return 0;
}

