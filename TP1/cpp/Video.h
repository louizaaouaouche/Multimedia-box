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

class Video:public Multimedia{
private:
    unsigned int duration{};
public:
    //Constructeurs
    Video();
    Video(std::string name , std::string pathname , unsigned int duration):Multimedia(name, pathname)
    {
        this->duration = duration;
    };

    //Destructeur
    ~Video(){
        std::cout << "Suppression de video " << getName() << " - ok\r" << std::endl;
    };
    
    //Getters
    unsigned int getDuration()const{
        return this->duration;
    };

    //Setters
    void setDuration(unsigned int duration){
        this->duration = duration;
    };

    //Afficheur
    void print(std::ostream & ostream)const override {
        Multimedia::print(ostream);
        ostream << " Duration:"  << this->duration;
    };

    //Lecteur
    void play() const{
        std::string syscall = std::string("mpv ")+ getPathname()+std::string(" &");
        system(syscall.c_str());
    }
};

//smart pointer
using VideoPtr = std::shared_ptr<Video>;

#endif