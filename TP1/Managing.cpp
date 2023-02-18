/**
 * @file Managing.cpp
 * @author Louiza AOUAOUCHE
 * @brief 
 */

#include "Managing.h"

/**
 * @brief constructeur par défaut de Managing
 */
Managing::Managing(){}

PhotoPtr Managing::createPhoto(std::string name, std::string fileName, double latitude, double longitude){
    PhotoPtr photo = PhotoPtr(new Photo(name,fileName,latitude,longitude));
    multimediasTab[name] = photo;
    return photo;
}


VideoPtr Managing::createVideo(std::string name, std::string fileName, int duration){
    VideoPtr video = VideoPtr(new Video(name, fileName,duration));
    multimediasTab[name]=video;
    return video;
}

FilmPtr Managing::createFilm(std::string name, std::string fileName, int duration, int number, const int * tabDurations){
    FilmPtr film = FilmPtr(new Film(name, fileName,duration, number, tabDurations));
    multimediasTab[name]=film;
    return film;
}

GroupPtr Managing::createGroup(std::string name){
    GroupPtr group =GroupPtr(new Group(name)); 
    groupsTab[name]=group;
    return group;
}

MultimediaPtr Managing::searchMultimedia(std::string name , std::ostream & ostream) const{
    auto idx = multimediasTab.find(name); 
    if (idx == multimediasTab.end()){ 
        ostream << "Erreur: Multimedia introuvable.";
        return nullptr;
    } else {
        
        return idx -> second ;
    }
}

void Managing::printMultimedia(std::string name , std::ostream & ostream) const{
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){ 
        ostream << "Erreur : Multimedia introuvable.";
    } else {
        return idx -> second -> print(std::cout);
    }
}

GroupPtr Managing::searchGroup(std::string name, std::ostream & ostream) const{
    auto idx = groupsTab.find(name);
    if (idx == groupsTab.end()){
        ostream << "Erreur : groupe introuvable";
        return nullptr;
    } else {
        return idx -> second ;
    }
}

void Managing::printGroup(std::string name,std::ostream & ostream) const{
    auto idx = groupsTab.find(name);
    if (idx == groupsTab.end()){
        ostream << "Erreur : groupe introuvable";
    } else {
        idx -> second -> printGroup(std::cout);
    }
}

void Managing::play(std::string name, std::ostream & ostream) const{
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){
        ostream  << "Erreur : Multimedia introuvable";
    } else {
        idx -> second -> play();
    }

}

void Managing::removeMultimedia(std::string name, std::ostream & ostream){
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){
        ostream  << "Erreur : Multimedia introuvable"; 
    } else {
        multimediasTab.erase(idx);
    } 
}

void Managing::removeGroup(std::string name, std::ostream & ostream){
    auto group = groupsTab.find(name);
    if (group == groupsTab.end()){
       ostream << "Erreur : Groupe introuvable";
    } else {
        groupsTab.erase(group); 
    }
}

