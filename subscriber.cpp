#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
//#include "std_msgs/String.h"
//#include "beginner_tutorials/AddTwoInts.h"
//#include "beginner_tutorials/prova.h"
//#include "beginner_tutorials/random_numbers.h"
#include <cstdlib>

int count=1;
double avg_p=0.0;
double avg_fin=0.0;
double max=0.0;
double min=0.0;
bool set_min=true;

void Callback(const sensor_msgs::Temperature& msg)
{
  //ROS_INFO("I heard: [%lf]", msg.temperature);
  if(set_min)
  {
    min=msg.temperature;
    set_min=false;
  }

  if(msg.temperature>max)
  {
    max=msg.temperature;
  }

  if(msg.temperature<min)
  {
    min=msg.temperature;
  }

  avg_p = avg_p+msg.temperature;
  avg_fin = avg_p/count;

  if(count%5==0)
  {
     //ROS_INFO("I heard: [%s]", msg.header);
     //ROS_INFO("I heard: [%lf]", msg.temperature);

     ROS_INFO("La temperatura massima e' %lf", max);

     ROS_INFO("La temperatura minima e' %lf", min);

     ROS_INFO("La temperatura media e' %lf", avg_fin);
  }

  count++;
}

/*bool add(beginner_tutorials::AddTwoInts::Request  &req, beginner_tutorials::AddTwoInts::Response &res, beginner_tutorials::prova::Request &pro, beginner_tutorials::prova::Response &prov)
{
  prov.ret=0;
  if(pro.count==4)
  {
    ROS_INFO("La temperatura attueale e': %lf", pro.temp);
    prov.ret=1;

    if(pro.temp>pro.max)
    {
      pro.max=pro.temp;
    }
    ROS_INFO("La temperatura massima e' %d", pro.max);

    if(pro.temp<pro.min)
    {
      pro.min=pro.temp;
    }
    ROS_INFO("La temperatura minima e' %d", pro.min);
  }

  
  
  return true;
}*/




int main(int argc, char **argv)
{
  
  //ros::init(argc, argv, "add_two_ints_server");
  ros::init(argc, argv, "sub");
  ROS_INFO("START");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("temp_sensor", 1000, Callback);

  //ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  //c++;

  ros::spin();

  /*ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();*/

  return 0;
}
