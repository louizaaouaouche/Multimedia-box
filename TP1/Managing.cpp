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

MultimediaPtr Managing::searchMultimedia(std::string name) const{
    auto idx = multimediasTab.find(name); 
    if (idx == multimediasTab.end()){ //on arrive à la fin = on a rien trouvé
        std::cout << "Error not found";
        return nullptr;
    } else {
        
        return idx -> second ;
    }
}

void Managing::printMult(std::string name) const{
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){ 
        std::cout  << "Error not found";
    } else {
        return idx -> second -> printVariables(std::cout);
    }
}

GrPtr Managing::searchGroups(std::string name) const{
    auto idx = groupsTab.find(name);
    if (idx == groupsTab.end()){
        std::cout  << "Error not found";
        return nullptr;
    } else {
        return idx -> second ;
    }
}

void Managing::printGroups(std::string name) const{
    auto idx = groupsTab.find(name);
    if (idx == groupsTab.end()){
        std::cout << "Error not found";
    } else {
        idx -> second -> printGroup(std::cout);
    }
}

void Managing::play(std::string name) const{
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){
        std::cout  << "Error not found";
    } else {
        idx -> second -> play();
    }

}

void Managing::removeMultimedia(std::string name){
    auto idx = multimediasTab.find(name);
    if (idx == multimediasTab.end()){
        std::cout  << "Error not found"; 
    } else {
        multimediasTab.erase(idx);
    } 
}

void Managing::removeGroup(std::string name){
    auto group = groupsTab.find(name);
    if (group == groupsTab.end()){
        std::cout  << "Error not found";
    } else {
        groupsTab.erase(group); 
    }
}

