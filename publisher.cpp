#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
#include "std_msgs/Float64.h"
#include <cstdlib>
#include <ctime>

float f=1;

/* Funzione per il settaggio della frequenza. Viene richiamata quando arriva un messaggio sul topic set_freq */
void set_frequenza(const std_msgs::Float64& msg)
{
  f=msg.data;
}

int main(int argc, char **argv)
{
  /* Inizializzazione per la generazione casuale dei numeri. Inserita per simulare l'invio delle temperature lette dal sensore */
  srand((unsigned)time(NULL));

  /* Inizializzazione e assegnazione univoca del nome del nodo */
  ros::init(argc, argv, "pub");

  ros::NodeHandle n;

  ros::Rate oneSecond(1);

  /* Definizione del publisher e del topic temp_sensor sul quale pubblicherà i messaggi di tipo sensor_msgs/Temperature. Il publisher rimane in attesa un secondo per permettere la connessione ai subscriber */
  ros::Publisher pub = n.advertise<sensor_msgs::Temperature>("temp_sensor", 1000);
 
  oneSecond.sleep();

  /* Definizione del subscriber e del topic set_freq dal quale riceve i messaggi di tipo std_msgs/Float64. Ogni volta che riceve un messaggio chiamerà la funzione set_frequenza */
  ros::Subscriber set = n.subscribe("set_freq", 1000, set_frequenza);
  
  /* Dichiarazione del messaggio di tipo sensor_msgs/Temperature */
  sensor_msgs::Temperature temp;
  
  while (ros::ok())
  {
    /* Comando per la generazione del loop alla frequenza f che viene settata mediante publisher esterno. Inizialmente 1 Hz */
    ros::Rate loop_rate(f);
    
    ROS_INFO("frequenza= %lf", f);

    /* Generazione randomica per simulare la temperatura letta dal sensore*/
    temp.temperature = (float)(rand()%15) + (float)rand() / (float)RAND_MAX;

    /* Pubblicazione del messaggio sul topic. Tutti i nodi connessi riceveranno lo stesso messaggio */
    pub.publish(temp);

    ROS_INFO("%lf", temp.temperature);

    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
