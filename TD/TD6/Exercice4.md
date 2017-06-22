


## Exercice 4. (Producteur / Consommateur avec tampon borné)

Un processus producteur produit des objets (des entiers) qui sont consommés par un processus
consommateur. Les objets sont consommés dans l'ordre de production. Pour que les deux processus
puissent s'exécuter en parallèle, avec des rythmes différents pour la production et la consommation, ils
partagent un tampon de taille N. L'accès au tampon constitue la section critique pour les deux processus.
- En utilisant un tampon circulaire de taille N géré par deux indices i_occupé (l'emplacement à
consommer) et i_libre (l'emplacement où produire), proposer une solution avec des sémaphores.

``` C
int* buffer [N];     //buffer
init(i_occupé,1)    //sémaphore initialisé à 1. Sert à la protection de la variable globale i_occupé,
                    // mais aussi à la synchronisation entre les 2 processus
init (i_libre,0)   // Initialisée à 0, car je veux que le consommateur prenne seulement si il y a de
                    // la matière dans le buffer
int i_libre=N        // N places de libre initialement
int i_occupé=0      // Rien dans le buffer

Producteur
P(i_occupé)           // On entre dans la section critique
  si i_occupé < N;      //tant que e tampon n'est pas plein
  *produire dans buffer[i_occupé%N]*    //on produit
  i_occupé++;
  i_libre++
  V(i_libre)                    // on incrémente le sémaphore i_libre pour autoriser le consommateur
V(i_occupé)                   // On incrémente i_occupé pour permettre au producteur de revenir déposer


Consommateur

P(i_libre)                // après autorisation du producteur, on entre
  si i_occupé > 0           // si il y a au moins 1 produit
   *recuperer dans buffer[i_occupé%N]*
   i_occupé --;
   i_libre++;
                                  // pas de V(i_libre), je préfère contrôler les entrées des consommateurs via le processus Producteur.
                                  // En effet, je considère que seulement quand un produit est mis, on avertit le consommateur qu'il peut le prendre. L'hypothèse est donc que un producteur ne va déposer que 1 seul produit. Si il veut en déposer un deuxième, il devra refaire le processus Producteur depuis le début
```
