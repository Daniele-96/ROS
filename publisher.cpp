#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
#include "std_msgs/Float64.h"
//#include "std_msgs/String.h"
//#include "beginner_tutorials/AddTwoInts.h"
//#include "beginner_tutorials/prova.h"
//#include "beginner_tutorials/random_numbers.h"
#include <cstdlib>
#include <ctime>

float f=0.1;

void set_frequenza(const std_msgs::Float64& msg)
{
  ROS_INFO("I heard: [%lf]", msg.data);
  f=msg.data;
}

int main(int argc, char **argv)
{
  /*long int a;
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }*/

  srand((unsigned)time(NULL));

  ros::init(argc, argv, "pub");

  ros::NodeHandle n;

  ros::Rate oneSecond(1);

  

  ros::Publisher pub = n.advertise<sensor_msgs::Temperature>("temp_sensor", 1000);
 
  oneSecond.sleep();

  ros::Subscriber set = n.subscribe("set_freq", 1000, set_frequenza);
  /*ros::Subscriber sub1 = n.subscribe("temp_sensor", 1000, set_freq);
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::prova>("add_two_ints");
  double x=1;
  ros::Rate loop_rate(x);
 
  beginner_tutorials::prova pr;
  sensor_msgs::Temperature temp;

  int x=0;
  int count=0;
  pr.request.temp = 0;
  pr.request.count = 0;
  pr.request.min=0;
  pr.request.max=0;*/
  //ros::Subscriber set = n.subscribe("set_freq", 1000, set_frequenza);

  //ros::spin();
  

  //ros::Subscriber set = n.subscribe("set_freq", 1000, set_frequenza);

  sensor_msgs::Temperature temp;
  //temp.temperature=NULL;

  //ROS_INFO("set %lf", set);
  while (ros::ok())
  {
    
    ros::Rate loop_rate(f);
    
    /*std::stringstream ss;
    ss << "ciao " << count;
    msg.data = ss.str();*/
     ROS_INFO("frequenza= %lf", f);
    temp.temperature = (float)(rand()%15) + (float)rand() / (float)RAND_MAX;
    pub.publish(temp);
    
    //pub.publish(temp);

    ROS_INFO("%lf", temp.temperature);
    
    /*if (client.call(pr))
    {
      //pr.request.temp=uniformReal(0,30);
      ROS_INFO("temperatura %d", x++);
      pr.request.count++;
      if(pr.response.ret==1)
      {pr.request.count=0;}
      
    }
    else
    {
      ROS_ERROR("Failed to call service add_two_ints");
      return 1;
    }*/
    

    
    ros::spinOnce();

    loop_rate.sleep();

    /*ros::spin();*/
    //++count;
  }

/////////////////////////////////////////////
/*
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::prova>("add_two_ints");
  beginner_tutorials::prova pr;
  pr.request.a = 1;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(pr))
  {
    ROS_INFO("prova +1: %ld", (long int)pr.response.b);
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    a = (long int)srv.response.x + 1;
    ROS_INFO("x+1: %ld", a);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }*/

  return 0;
}
