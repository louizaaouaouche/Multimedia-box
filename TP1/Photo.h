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

class Photo:public Multimedia{
private:
    double latitude{};
    double longitude{};
public:
    //Constructeurs
    Photo();
    Photo(std::string name , std::string pathname , double latitude , double longitude):Multimedia(name, pathname){
        this->latitude = latitude;
        this->longitude = longitude;
    };

    //Destructeur
    ~Photo(){
        std::cout << "Suppression de photo " << getName() << " - ok\r" << std::endl;
    };
    

    //Getters
    double getLatitude()const{
        return this->latitude;
    };
    double getLongitude()const{
        return this->longitude;
    };

    //Setters
    void setLatitude(double latitude){
        this->latitude = latitude;
    };
    void setLongitude(double longitude){
        this->longitude = longitude;
    };

    //Afficheur
    void print(std::ostream & ostream)const override {
        Multimedia::print(ostream);
        ostream << "Latitude:"  << this->latitude << ". Longitude: "<< this->longitude << std::endl;
    };

    //Lecteur
    void play() const{
        std::string syscall = std::string("imagej ")+getPathname()+std::string(" &");
        system(syscall.c_str());
    }
};

//smart pointer
using PhotoPtr = std::shared_ptr<Photo>; 

#endif
