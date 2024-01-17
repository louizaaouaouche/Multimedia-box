/**
 * @file Photo.h
 * @author Louiza AOUAOUCHE
 */
#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include <memory>
#include "Multimedia.h"

/**
 * @brief Classe Photo heritant de l'objet Multimedia
 */
class Photo:public Multimedia{
friend class Managing;
private:
    double latitude{};
    double longitude{};

protected: 

    /**
     * @brief Constructeur par defaut de l'Objet Photo
     */
    Photo();
    /**
     * @brief Constructeur de l'object Photo
     * 
     * @param name nom de la photo
     * @param pathname chemin vers la photo
     * @param latitude largeur
     * @param longitude longueur
     */
    Photo(std::string name , std::string pathname , double latitude , double longitude):Multimedia(name, pathname){
        this->latitude = latitude;
        this->longitude = longitude;
    };

    
public:
    /**
     * @brief Destructeur de l'Objet Photo
     */
    ~Photo(){
        std::cout << "Suppression de photo " << getName() << " - ok"<< std::endl;;
    };
    
    /**
     * @brief Getter de la Latitude de l'Objet
     * 
     * @return double 
     */
    double getLatitude()const{
        return this->latitude;
    };

    /**
     * @brief Getter de la Longitude de l'Objet
     * 
     * @return double 
     */
    double getLongitude()const{
        return this->longitude;
    };

    /**
     * @brief Modifie la Latitude de L'Objet
     * @param latitude 
     */
    void setLatitude(double latitude){
        this->latitude = latitude;
    };

    /**
     * @brief Modifie la Longitude de L'Objet
     * @param longitude 
     */
    void setLongitude(double longitude){
        this->longitude = longitude;
    };

    /**
     * @brief Affiche le contenu de l'objet Photo
     * @param ostream flux/support d'affichage
     */
    void print(std::ostream & ostream)const override {
        Multimedia::print(ostream);
        ostream << " Latitude:"  << this->latitude << ". Longitude: "<< this->longitude;
    };

    /**
     * @brief Lecteur d'objet Photo
     */
    void play() const{
        std::string syscall = std::string("imagej ")+getPathname()+std::string(" &");
        system(syscall.c_str());
    }
};

//smart pointer
using PhotoPtr = std::shared_ptr<Photo>; 

#endif
