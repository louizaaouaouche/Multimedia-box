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
A partir de la classe mère Multimedia on crée deux sous-classes: Classe Photo et Classe Video.
- **Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?**
  - On appelle ce type de méthode une méthode virtuelle. On doit les déclarer dans la classe de base.
  ```cpp
  virtual type method(params) = 0;
  ```

- **Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?**
  - La classe de base possèdera une méthode abstraite qui ne permet plus l'instanciation.

## 5e Etape: Traitement uniforme (en utilisant le polymorphisme)
On traite de manière uniforme une liste comprenant à la fois des photos et des vidéos sans avoir à se préoccuper de leur type.
- **Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?**
  -La propriété caractéristique de l'orienté objet qui permet de faire cela est le polymorphisme. C'est la capacité pour un objet ou une fonction à avoir plusieurs formes ou comportements différents. Il en existe deux types : le polymorphisme de surcharge (plusieurs fonctions  partagent le même nom, avec des signatures différentes.) et le polymorphisme de substitution (même nom et signature de fonction pour différentes classes héritant d'une classe de base et s'adapte selon l'argument.) C'est le cas pour la fonction print et play
- **Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?**
  - En c++, il est nécessaire de déclarer la méthode de la classe de base comme étant virtuelle en utilisant le mot-clé virtual. Cela indique au compilateur que la méthode peut être redéfinie dans les classes dérivées. Si la méthode n'est pas déclarée virtuelle, le compilateur appelle la version de la méthode de la classe de base même si on utilise une référence ou un pointeur à une instance de la classe dérivée.
- **Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.**
  - Les élements du tableau sont de type pointeurs car tous les éléments d'un tableau doivent avoir la même taille en mémoire ce qui n'est pas le cas si les éléments étaients des objets. On doit, de ce fait, pouvoir assurer le polymorphisme. Il est nécessaire d'utiliser *delete* pour supprimer tout pointeur qui n'est plus utilisé afin d'éviter les problèmes de fuites de mémoire. En Java, tout est référence, ainsi, on stocke dans le tableau des références d'objets et c'est le garbage collector qui s'occupe de gérer les suppressions et tout ce qui est relatif aux fuites mémoires. 

## 6e étape. Films et tableaux
- Afin que la classe Film puisse assurer la pérenité de ses données, dont le tableau des durées, il faut les proteger. 
- Le modifieur du tableau prend en argument un pointeur vers un tableau de durées ainsi que le nombre de chapitres, et copie les données dans un nouveau tableau. Il libère ensuite la mémoire de l'ancien tableau. Le destructeur de la classe s'assure également de libérer la mémoire allouée pour le tableau.
- Pour que le tableau retourné par l'accesseur ne soit pas modifié, on précède la signature de la fonction par ```const``` et on renvoie une copie du tableau. Il faut que la copie en soit pas superficielle. Pour cela, on peut créer un opérateur de copie et surcharger l'opérateur d'affectation.

## 7e étape. Destruction et copie des objets
- **Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ? **
  - Seule la classe ```Film``` a un attribut alloué sur le tas. Il est important de s'assurer qu'il n'y ait pas de fuite de mémoire en appelant delete dans un destructeur pour la classe Film pour libérer la mémoire allouée avec new (tableau des durées).

- **La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?**
  - Pour la copie d'objet, par défaut il n'y que copie de pointeurs (qui vont donc pointer sur le même objet). Pour cela, on peut définir un constructeur de copie et un opérateur d'affectation qui assurent une copie de l'objet du tableau de durées. 

## 8e étape. Créer des groupes
- **Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.**
  - La classe group doit contenir des pointeurs d'objets et non les objets eux mêmes car ils peuvent ne pas être de même taille. De plus, vu que la classe ne doit pas détruire un objet (car il peut appartenir à plusieurs groupes), il est plus juste d'avoir une liste de pointeurs qui une fois détruits, seuls les liens de la liste vers ses objets sont rompus sans toucher aux objets eux mêmes.
  - En Java, on utilise des références (proches des pointeurs), cela dit, on ne gère pas manuellement la durée de vie des objets.

## 9e étape. Gestion automatique de la mémoire
Ajout des smarts pointers (shared_ptr).

## 10e étape. Gestion cohérente des données
- **Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?**
  -  Afin que la seule classe servant à manipuler les objets puisse en créer de nouveau il faut déclarer les constructeurs de classe ```Photo```, ```Video```, ```Film``` et ```Group``` en ```protected``` et également déclarer la classe Managing en tant que friend de celles-ci.
## 11e étape. Client / serveur

## 12e étape. Sérialisation / désérialisation

## 13e étape. Traitement des erreurs
