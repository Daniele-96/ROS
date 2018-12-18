#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  /* Inizializzazione e assegnazione univoca del nome del nodo */
  ros::init(argc, argv, "set");
  
  /* Controllo dell'inserimento di un paramentro da riga di comando per la nuova frequenza da settare */
  if (argc != 2)
  {
    ROS_INFO("Inserire frequenza");
    return 1;
  }

  ROS_INFO("START");
  
  ros::NodeHandle n;
  ros::Rate oneSecond(1);

  /* Dichiarazione del messaggio di tipo std_msgs/Float64 e assegnazione nel campo data del valore inserito da riga di comando. Questa sarà la nuova frequenza da settare */
  std_msgs::Float64 freq;

  freq.data=atof(argv[1]);

  while(ros::ok())
  {
    /* Definizione del publisher e del topic temp_sensor sul quale pubblicherà i messaggi di tipo sensor_msgs/Temperature. Il publisher rimane in attesa un secondo per permettere la connessione ai subscriber */
    ros::Publisher set = n.advertise<std_msgs::Float64>("set_freq", 1000);

    oneSecond.sleep();
    
    /* Pubblicazione del messaggio sul topic. Tutti i nodi connessi riceveranno lo stesso messaggio. Dopo un secondo di attesa per permettere l'invio e l'effettiva ricezione del messaggio inviato il nodo viene distrutto */
    set.publish(freq);

    oneSecond.sleep();
    
    ros::shutdown();
  }
  return 0;
}

