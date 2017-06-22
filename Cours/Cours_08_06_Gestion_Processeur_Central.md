#Gestion du Processeur Central

##Concept d'ordonnancement des processus

- Plusieurs processus en concurrence dans les systèmes multiprogrammés. Concurrence arrive quand 2 processus sont prêt en même temps.
- Un choix doit être fait quand au prochain process à exécuter.
- Minimiser le temps global d'exécution

##Deux catégories d'algorithmes
- Ordonnanceur du CPU permet de décider à quel processus dans la file d'attente des processus prêts attribuer le contrôle du CPU.
- 2 catégs: Sans réquisition du CPU (stratégie non préemptive), avec réquisition du CPU (stratégie préemptive).

1 ère méthode:

- De moins en moins utilisé.
- FCFS : tâches ordonnancées dans l'ordre où elles sont reçues. Le processus qui sollicite le CPU le premier sera servie le premier => structure de file.
