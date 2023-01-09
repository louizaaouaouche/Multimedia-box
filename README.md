# INF224

Le but de ce projet est de créer l'ébauche du logiciel d'une set-top box multimédia permettant de jouer de la musique, des vidéos, des films, d'afficher des photos, etc. Ce logiciel a été realisé par étapes, en se limitant à la déclaration et l'implémentation de quelques classes et fonctionnalités typiques que complétées progressivement. 

## 1e Etape: Démarrage
La première étape consiste à mettre en place un environnement pour le projet:
- Définir l'outil de programmation : VSCODE
- Tester le fonctionnement du makefile (et à fortiori le fonctionnement du langage c++ sur la machine utilisée)

## 2e Etape: Classe de base
On crée la classe de base Multimedia. Pour cela on aura deux fichiers:
- *Multimedia.h* : contient initialement
  - Deux variables d'instance: Le nom du multimedia (std::string) , le pathname associé (std::string). 
  - Des méthodes classiques (Deux constructeurs, un destructeur, getters, setters)
  - Une méthode d'afficage 
- *Multimedia.cpp* : contient l'implémentation de ce qui a été déclaré dans le .h 

## 3e Etape: Programme de test
Une fois que le Makefile a été modifié, on modifie le fichier *main.cpp* afin de tester la classe:
```cpp
#include <iostream>
#include "Multimedia.h"

int main(int argc, const char* argv[]){
  Multimedia *media1 = new Multimedia();
  Multimedia *media2 = new Multimedia("image" , "image.png");

  media1->setName("image2");
  media1->setPathname("image2.png");

  media1->print(std::cout);
  media2->print(std::cout);
  return 0;   
}
```

## 4e Etape: Photos et videos
A partir de la classe mère Multimedia on crée deux sous-classes:
**Classe Photo**:
- Deux variables d'instance : latitude (de type double), longitude (de type double)
- Méthodes classiques : constructeurs, destructeur, setters
- Méthodes relatives à la classe mère : affichage, jouer
**Classe Video**:
- Une variable d'instance : durée (de type entier)
- Méthodes classiques : constructeurs, destructeur, setters
- Méthodes relatives à la classe mère : affichage, jouer

## 5e Etape: Traitement uniforme (en utilisant le polymorphisme)
On traite de manière uniforme une liste comprenant à la fois des photos et des vidéos sans avoir à se préoccuper de leur type.
- *Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?* 
La propriété caractéristique de l'orienté objet qui permet de faire cela est le polymorphisme. C'est la capacité pour un objet ou une fonction à avoir plusieurs formes ou comportements différents. Il en existe deux types : le polymorphisme de surcharge (plusieurs fonctions  partagent le même nom, avec des signatures différentes.) et le polymorphisme de substitution (même nom et signature de fonction pour différentes classes héritant d'une classe de base et s'adapte selon l'argument.) C'est le cas pour la fonction print et play
- *Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?*
En c++, il est nécessaire de déclarer la méthode de la classe de base comme étant virtuelle en utilisant le mot-clé virtual. Cela indique au compilateur que la méthode peut être redéfinie dans les classes dérivées. Si la méthode n'est pas déclarée virtuelle, le compilateur appelle la version de la méthode de la classe de base même si on utilise une référence ou un pointeur à une instance de la classe dérivée.
- *Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.*
Les élements du tableau sont de type pointeurs car tous les éléments d'un tableau doivent avoir la même taille en mémoire ce qui n'est pas le cas si les éléments étaients des objets.
## 6e étape. Films et tableaux

## 7e étape. Destruction et copie des objets

## 8e étape. Créer des groupes


## 9e étape. Gestion automatique de la mémoire

## 10e étape. Gestion cohérente des données

## 11e étape. Client / serveur

## 12e étape. Sérialisation / désérialisation

## 13e étape. Traitement des erreurs
