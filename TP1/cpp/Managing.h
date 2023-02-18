/**
 * @file Managing.h
 * @author Louiza AOUAOUCHE
 **/
#ifndef MANAGING_H
#define MANAGING_H

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <ostream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"


class Managing{
private:

    std::map<std::string, MultimediaPtr> multimediasTab ; //table associative des multimedias
    std::map<std::string, GroupPtr> groupsTab; // table associative des groupes

public:

    Managing();

    /**
     * @brief crée un objet photo
     * @param name
     * @param fileName
     * @param latitude
     * @param longitude
     * @return
     */
    PhotoPtr createPhoto(std::string name, std::string fileName, double latitude, double longitude);

    /**
     * @brief crée un objet vidéo
     * @param name
     * @param fileName
     * @param duration
     * @return
     */
    VideoPtr createVideo(std::string name, std::string fileName, int duration);

    /**
     * @brief crée un multimedia Film
     * @param name 
     * @param fileName 
     * @param duration 
     * @param length 
     * @param tabDurations 
     * @return FilmPtr 
     */
    FilmPtr createFilm(std::string name, std::string fileName, int duration, int length, const int * tabDurations);

    /**
     * @brief crée un groupe
     * @param name
     * @return GroupPtr
     */
    GroupPtr createGroup(std::string name);

    /**
     * @brief fait le recherche un objet multimedia à partir de son nom
     * @param name
     * @return
     */
    MultimediaPtr searchMultimedia(std::string name , std::ostream & ostream) const;

    /**
     * @brief Recherche d'un groupe à partir de son nom
     * @param name
     * @return GroupPtr
     */
    GroupPtr searchGroup(std::string name, std::ostream & ostream) const;


    /**
     * @brief affichage d'un objet multimedia à partir de son nom
     * @param name
     */
    void printMultimedia(std::string name, std::ostream & ostream) const;

    /**
     * @brief Affichage d'un groupe à partir de son nom
     * @param name
     */
    void printGroup(std::string name, std::ostream & ostream) const;

    /**
     * @brief jouer un objet multimedia
     * @param name
     */
    void play(std::string name, std::ostream & ostream) const;

    /**
     * @brief supprie un objet multimedia à partir de son nom
     * @param name
     */
    void removeMultimedia(std::string name, std::ostream & ostream);

    /**
     * @brief supprime un groupe à partir de son nom
     * @param name
     */
    void removeGroup(std::string name, std::ostream & ostream);
};

#endif // MANAGING_H