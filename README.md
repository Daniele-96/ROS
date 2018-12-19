# SIMULAZIONE SENSORE DI TEMPERATURA
Simulazione di un sensore di temperatura e della comunicazione tra n nodi che scambiano messaggi tra di loro. Abbiamo un nodo principale, *pub*, che funge sia da publisher che da subscriber. Genera due topic, uno per l'invio delle temperature misurate e un altro che rimane in ascolto in attesa di un messaggio per il settaggio di una nuova frequenza di invio dati. Possiamo trovare poi altri due nodi, *sub* e *set*. Il primo funge da subscriber e rimane in ascolto sul topic *temp_sensor* in attesa di ricevere delle temperature che poi verranno elaborate per trovare massimo, minimo e media delle temperature ricevute. Stamperà a video i risultati calcolati ogni n letture. Il secondo si occupa di settare la nuova frequenza di invio delle temperature grazie al topic *set_freq* sul qualche il nodo *pub* rimane in ascolto. Viene richiamato ogni qualvolta l'utente vuole cambiare la frequenza di invio delle letture.

## Linguaggio di programmazione
Codici scritti in C++ utilizzando anche librerie ROS necessarie per la corretta generazione e comunicazione tra i nodi.

## Building
Dopo aver creato tutte le directory ed aver installato tutti i pacchetti necessari per lavorare correttamente in un workspace ROS si può iniziare con la compilazione da terminale del progetto ROS. Bisogna lavorare sempre nel workspace creato ed eseguire alcune azioni preliminari.

    roscore

Da terminale digitare il comando sopra riportato per far si che vengano generati un ROS master e un server contenente tutti i comandi necessari per l'utilizzo corretto di un sistema ROS.

    cd catkin_ws
    source ./devel/setup.bash

Aprendo un altro terminale si cambia directory entrando in quella contenente tutti i pacchetti del workspace di ROS e digitando la seconda riga di comando avremo accesso a tutti i comandi ROS. Per ogni nuovo terminale aperto dovremo ripetere le due righe di comando sopra riportate.

    catkin_make

Per la compilazione e la generazione degli eseguibili basta digitare da terminale la riga di codice soprastante. Assicurarsi di essere nella directory del workspace ROS.

## Running
Una volta compilati i file basterà mandare in esecuzione tramite terminale gli eseguibili generati. Sono necessari tre file per il corretto funzionamento di questa simulazione quindi in tre terminali diversi dovremo eseguire la seguente riga di codice:

    rosrun <directory_finale> <nome_file_.cpp>

Andando a sostituire nella maniera corretta i termini all' interno di <>. Per questa simulazione la directory finale è *beginner_tutorials* mentre i tre file che saranno mandati in esecuzione sono rispettivamente e nel seguente ordine *subscriber*, *publisher*, *set freq*. 

## Debug
ROS sfrutta alcuni strumenti di debug necessari per la verifica di un corretto funzionamento del programma in esecuzione.

### Rosbag
Strumento di debug che rimane in ascolto su tutti i nodi e registra informazioni e scambi di messaggi che avvengono tra questi. I risultati vengono scritti su un file creato ogni volta che questo comando viene chiamato da terminale. Il file sarà caratterizzato dal seguente nome <anno_giorno_ora>.bag e conterrà tutte le informazioni registrate da quando è stato mandato in esecuzione fino alla sua terminazione. Viene salvato all'interno della directory in cui ci si trova al momento dell'esecuzione della riga di comando.

    rosbag record

Per analizzare quello che è scritto all'interno del file si può utilizzare la seguente riga di comando da terminale che ci mostrerà il contenuto del file.

    rosbag info <nome_file>

Inoltre si può mandare in esecuzione ciò che è stato registrato su un file .bag grazie al seguente comando che replica tutte le informazioni e i messaggi contenuti al suo interno.

    rosbag play <nome_file>

### Rostopic
Strumento di debug che viene utilizzato per avere informazioni sui topic in esecuzione. Si possono utilizzare delle opzioni per avere informazioni più specifiche sui topic. Alcuni esempi:

    rostopic info

Stampa sul terminale delle informazione sui topic attivi in quel momento.

    rostopic list

Stampa una lista dei topic attivi in quel momento.

    rostopic pub <topic> <messaggio>

Pubblica su un topic un messaggio inserito da terminale dall'utente.

Ci sono altre opzioni utilizzabili con il rostopic ma per questa simulazione queste sono le più utilizzate.

### Rosgraph e rqt_graph
Strumenti di debug che generano dei grafici sulla situazione attuale nel momento in cui vengono chiamati. Il primo lavora da terminale ed è necessario mandare in esecuzione la seguente riga di comando per visualizzare nodi, topic e comunicazioni sul terminale

    rosgraph

Il secondo genera un finestra all'interno della quale viene rappresentato un grafico contenente i nodi, i topic e i messaggi che vengono scambiati istante per istante sui topic stessi. Si può richiamare utilizzando la seguente riga di comando sul terminale

    rosrun rqt_graph rqt_graph
