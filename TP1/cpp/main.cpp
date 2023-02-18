/**
 * @file main.cpp
 * @author Louiza AOUAOUCHE
 */

#define VERSION_AVEC_SERVEUR

#include <iostream>
#include <vector>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Managing.h"
using namespace std;

#ifdef VERSION_SANS_SERVEUR
int main(int argc, const char* argv[]){
    /*
    //PART 1 to 3
    std::cout << "--- PARTIE 1 - 3 : MULTIMEDIA ---" << std::endl;
    Multimedia *media1 = new Multimedia();
    Multimedia *media2 = new Multimedia("image" , "../data/photo1.jpg");
    
    media1->setName("image2");
    media1->setPathname("image2.png");

    media1->print(std::cout);
    media2->print(std::cout);
    */

    //PART 4
    /*
    std::cout << "--- PARTIE 4 : PHOTO/VIDEO ---" << std::endl;
    Photo *photo1 = new Photo("photo1","../data/photo1.jpg", 3, 4);
    photo1->print(std::cout);

    Video *video1 = new Video("video1","../data/video1.mp4", 3);
    video1->setDuration(4);
    video1->print(std::cout);
    */
    
    //PART 5
    /*
    std::cout << "--- PARTIE 5 : POLYMORPHISME ---" << std::endl;
    Multimedia* listMultimedia[3];
    listMultimedia[0] = new Photo("Photo1", "../data/photo1.jpg", 5, 10);
    listMultimedia[1] = new Video("Video1", "../data/video1.mp4", 5);


    for(int i = 0 ; i<2; i++){
        listMultimedia[i]->play(); //lancer le i-ème média de la liste
    }
    */

    //PART 6 / 7
    /*
    std::cout << "--- PARTIE 6 - 7 : FILMS & TABLEAUX ---" << std::endl;
    
    int *tabDurations = new int[2]{22, 20};

    Film *film = new Film("titatic", "../data/titatic.mp4", 42, 2, tabDurations);
    film->print(std::cout);
    
    //--

    delete[] tabDurations;
    tabDurations = new int[2]{60, 50};
    //film2 est crée comme pointeur sur film
    Film *film2(film);
    //On modifie le tableau des durées des chapitres sur film2
    //On voit comment cela influe sur film
    film2->setTabDurations(tabDurations, 2);
    film->print(std::cout);*/

    //PART 8 & 9
    /*
    std::cout << "--- PARTIE 8 - 9 : GROUPE ---" << std::endl;
    Group *group1 = new Group("group 1");
    Group *group2 = new Group("group 2");   
    std::shared_ptr<Multimedia> video1(new Video("video1", "../data/video1.mp4", 10));
    std::shared_ptr<Multimedia> photo1(new Photo("photo", "../data/photo1.jpg", 10, 10));
    group1->push_back(video1);
    group1->push_back(photo1);
    group2->push_back(photo1);
    group1->printGroup(std::cout);
    group2->printGroup(std::cout);
    delete group1;
    delete group2;
    */  

    //PART 10
    
    std::cout << "--- PARTIE 10 : GESTION DES DONNEES ---" << std::endl;
    
    Managing* gestion = new Managing();
    std::shared_ptr<Photo> photo(gestion->createPhoto("photo", "../data/photo1.jpg", 3, 3));
    std::shared_ptr<Video> video = gestion->createVideo("video", "../data/video1.mp4", 3);
    int *tabDurations = new int[2]{60, 50};
    std::shared_ptr<Film> film = gestion->createFilm("film", "../data/", 110, 2, tabDurations);
    std::shared_ptr<Group> group = gestion->createGroup("group");
    group->push_back(photo);
    group->push_back(video);
    group->push_back(film);
    gestion->printMultimedia("photo", std::cout) ;
    gestion->printMultimedia("photo20" , std::cout);
    return 0;   

}

#endif

#ifdef VERSION_AVEC_SERVEUR

#include <sstream>
#include "tcpserver.h"

const int PORT = 3331;

int main(int argc, const char *argv[]){
    Managing *gestion = new Managing();
    shared_ptr<Group> group1 = gestion->createGroup("group1");
    shared_ptr<Photo> photo1 = gestion->createPhoto("photo1", "../data/photo1.jpg", 10, 10);
    shared_ptr<Video> video2 = gestion->createVideo("video1", "../data/video1.mp4", 5);
    int *tabDurations = new int[2]{50,60 };
    shared_ptr<Film> movie1 = gestion->createFilm("film1", "../data/", 110, 2, tabDurations);
    group1->push_back(photo1);
    group1->push_back(video2);
    group1->push_back(movie1);

    // Création d'un protocole de connexion
    auto* server = new TCPServer( [&](std::string const& request, std::string& response) {

        stringstream srequest {request};
        stringstream sresponse {};

        //découpage de la requete
        string action {};
        string name {};
        
        srequest >> action;
        srequest >> name;
        
        //Recherche d'un objet multimedia
        if (action == "searchMultimedia"){ 
            auto result = gestion->searchMultimedia(name , sresponse);
            if (result == nullptr){
                response = sresponse.str() ;
            } else {
                result->print(sresponse);
                response = sresponse.str() ;
            }
        //Recherche d'un groupe
        } else if (action == "searchGroup"){ 
            auto result = gestion->searchGroup(name, sresponse);
            if (result == nullptr){
                response = sresponse.str() ;
            } else {
                result->printGroup(sresponse);
                response = sresponse.str() ;
            }
        //Affichage d'un multimedia
        }else if (action == "printMultimedia") {
            gestion->printMultimedia(name, sresponse);
            response = sresponse.str();
            
        }
        //Affichage d'un groupe
        else if (action == "printGroup") {
            gestion->printGroup(name, sresponse);
            response = sresponse.str() ;
        }
        //Jouer un multimedia
        else if (action == "play"){
            auto result = gestion->searchMultimedia(name, sresponse);
            if (result == nullptr){
                response = sresponse.str() ;
            }else{
                result->play();
                response = "Affichage ok";
            }
        }

        else {
            response = "Erreur: requete non comprise";
        }

        std::cerr << "Reponse a la requete:" << response<< std::endl;

        return true;
    });

    //gestion de la connexion
    std::cout << "Lancement du serveur sur le port: " << PORT<< std::endl;
    int status = server->run(PORT);

    if (status < 0){
        std::cerr << "Lancement impossible du serveur sur le port " << PORT << ", status: " << status << std::endl;
        return 1;
    }
    
    return 0;
   
}

#endif
