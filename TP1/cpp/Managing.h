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

/**
 * @brief Classe Managing permettant la gestion des multimedias
 */
class Managing{
private:

    std::map<std::string, MultimediaPtr> multimediasTab ; //table associative des multimedias
    std::map<std::string, GroupPtr> groupsTab; // table associative des groupes

public:

    Managing();

    /**
     * @brief crée un objet photo
     * @param name nom de la photo
     * @param fileName chemin vers la photo
     * @param latitude largeur
     * @param longitude longueur
     * @return Pointeur vers la photo cree
     */
    PhotoPtr createPhoto(std::string name, std::string fileName, double latitude, double longitude);

    /**
     * @brief crée un objet video
     * @param name nom de la video
     * @param fileName chemin vers la video
     * @param duration duree de la video
     * @return pointeur vers la video cree
     */
    VideoPtr createVideo(std::string name, std::string fileName, int duration);

    /**
     * @brief crée un multimedia Film
     * @param name nom du film
     * @param fileName chemin vers le film
     * @param duration duree u film
     * @param length nombre de chapitres
     * @param tabDurations durees de chacun de chapitres
     * @return Pointeur vers le film cree
     */
    FilmPtr createFilm(std::string name, std::string fileName, int duration, int length, const int * tabDurations);

    /**
     * @brief crée un groupe
     * @param name nom du groupe
     * @return Pointeur vers le groupe cree
     */
    GroupPtr createGroup(std::string name);

    /**
     * @brief fait le recherche un objet multimedia à partir de son nom
     * @param name nom du multimedia a rechercher
     * @param ostream support d'affichage
     * @return Pointeur du multimedia recherche, null sinon
     */
    MultimediaPtr searchMultimedia(std::string name , std::ostream & ostream) const;

    /**
     * @brief Recherche d'un groupe à partir de son nom
     * @param name nom du groupe a rechercher
     * @param ostream support d'affichage
     * @return Pointeur du groupe recherche, nulls sinon
     */
    GroupPtr searchGroup(std::string name, std::ostream & ostream) const;


    /**
     * @brief affichage d'un objet multimedia à partir de son nom
     * @param name nom du multimedia a afficher
     * @param ostream support d'affichage
     */
    void printMultimedia(std::string name, std::ostream & ostream) const;

    /**
     * @brief Affichage d'un groupe à partir de son nom
     * @param name nom du groupe
     * @param ostream support d'affichage
     */
    void printGroup(std::string name, std::ostream & ostream) const;

    /**
     * @brief jouer un objet multimedia
     * @param name nom du multimedia
     * @param ostream support d'affichage
     */
    void play(std::string name, std::ostream & ostream) const;

    /**
     * @brief supprime un objet multimedia à partir de son nom
     * @param name nom du multimedia
     * @param ostream support d'affichage
     */
    void removeMultimedia(std::string name, std::ostream & ostream);

    /**
     * @brief supprime un groupe à partir de son nom
     * @param name nom du groupe
     * @param ostream support d'affichage
     */
    void removeGroup(std::string name, std::ostream & ostream);
};

#endif // MANAGING_H