#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia{

private:
    std::string name;
    std::string pathname;
public:
    //Constructeurs
    Multimedia();
    Multimedia(std::string name , std::string pathname);

    //Destructeur
    ~Multimedia();

    //Getters
    std::string getName()const;
    std::string getPathname()const;

    //Setters
    void setName(std::string name);
    void setPathname(std::string pathname);

    //Afficheur
    virtual void print(std::ostream & ostream)const;

    //Lecteur multimedia
    virtual void play() const = 0;
};

#endif