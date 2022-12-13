#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

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
    ~Video();
    
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
        ostream << "Duration:"  << this->duration  << std::endl;
    };
};

#endif