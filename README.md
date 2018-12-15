# SIMULAZIONE SENSORE DI TEMPERATURA
Simulazione di un sensore di temperatura e della comunicazione tra n nodi che scambiano messaggi tra di loro. Abbiamo un nodo principale, *pub*, che funge sia da publisher che da subscriber. Genera due topic, uno per l'invio delle temperature misurate e un altro che rimane in ascolto in attesa di un messaggio per il settaggio di una nuova frequenza di invio dati. Possiamo trovare poi altri due nodi, *sub* e *set*. Il primo funge da subscriber e rimane in ascolto sul topic *temp_sensor* in attesa di ricevere delle temperature che poi verranno elaborate per trovare massimo, minino e media delle temperature ricevute. Stamperà a video i risultati calcolati ogni n letture. Il secondo si occupa di settare la nuova frequenza di invio delle temperature grazie al topic *set_freq* sul qualche il nodo *pub* rimane in ascolto.
