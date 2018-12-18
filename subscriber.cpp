#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
#include <cstdlib>

int count=1;
double avg_p=0.0;
double avg_fin=0.0;
double max=0.0;
double min=0.0;
bool set_min=true;

/* Funzione di callback che viene richiamata quando arriva un messaggio sul topic temp_sensor. Si occupa di svolgere le operazioni di calcolo una volta che riceve dei messaggi da parte del publisher. Calcola massimo, minimo e media delle temperature ricevute */
void Callback(const sensor_msgs::Temperature& msg)
{
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
     ROS_INFO("Misura numero %d", count);

     ROS_INFO("La temperatura massima e' %lf", max);

     ROS_INFO("La temperatura minima e' %lf", min);

     ROS_INFO("La temperatura media e' %lf\n", avg_fin);
  }

  count++;
}

int main(int argc, char **argv)
{
  /* Inizializzazione e assegnazione univoca del nome del nodo */
  ros::init(argc, argv, "sub");
  ROS_INFO("START");
  ros::NodeHandle n;

  /* Definizione del subscriber e del topic temp_sensor dal quale riceve i messaggi di tipo sensor_msgs/Temperature. Ogni volta che riceve un messaggio chiamerà la funzione Callback */
  ros::Subscriber sub = n.subscribe("temp_sensor", 1000, Callback);

  ros::spin();

  return 0;
}
