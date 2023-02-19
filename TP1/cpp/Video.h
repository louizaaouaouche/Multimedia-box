/**
 * @file Video.h
 * @author Louiza AOUAOUCHE
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include <memory>
#include "Multimedia.h"

/**
 * @brief Classe Video heritant de l'objet Multimedia
 */
class Video:public Multimedia{
private:
    unsigned int duration{};
public:
    /**
     * @brief Constructeur par defaut de l'objet Video
     */
    Video();

    /**
     * @brief Constructeur de l'objet Video
     * 
     * @param name nom de la video
     * @param pathname chemin vers la video
     * @param duration duree de la video
     */
    Video(std::string name , std::string pathname , unsigned int duration):Multimedia(name, pathname)
    {
        this->duration = duration;
    };

    /**
     * @brief Destructeur de l'objet Video
     */
    ~Video(){
        std::cout << "Suppression de video " << getName() << " - ok\r" << std::endl;
    };
    
    /**
     * @brief Getter de la Duration de l'Objet
     * 
     * @return unsigned int 
     */
    unsigned int getDuration()const{
        return this->duration;
    };

    /**
     * @brief Modifie la Duration de l'Objet
     * @param duration 
     */
    void setDuration(unsigned int duration){
        this->duration = duration;
    };

    /**
     * @brief Affiche le contenu de l'objet Video
     * @param ostream flux/support d'affichage
     */
    void print(std::ostream & ostream)const override {
        Multimedia::print(ostream);
        ostream << " Duration:"  << this->duration;
    };

    /**
     * @brief Lecteur d'objet Video
     */
    void play() const{
        std::string syscall = std::string("mpv ")+ getPathname()+std::string(" &");
        system(syscall.c_str());
    }
};

//smart pointer
using VideoPtr = std::shared_ptr<Video>;

#endif