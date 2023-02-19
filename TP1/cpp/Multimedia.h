/**
 * @file Multimedia.h
 * @author Louiza AOUAOUCHE
 */
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <memory>

class Multimedia{

private:
    std::string name;
    std::string pathname;

protected:
    /**
     * @brief Constructeur par defaut de l'objet Multimedia
     */
    Multimedia();

    /**
     * @brief Constructeur de l'objet Multimedia
     */
    Multimedia(std::string name , std::string pathname);

    
public:

    /**
     * @brief Destructeur de l'objet Multimedia
     */
    ~Multimedia();

    /**
     * @brief Renvoie le nom du Multimedia
     * @return std::string 
     */
    std::string getName()const;

    /**
     * @brief Renvoie le chemin vers le Multimedia
     * @return std::string 
     */
    std::string getPathname()const;

    /**
     * @brief Modifie l'attribut name
     * @param name nom du Multimedia
     */
    void setName(std::string name);

    /***
     * @brief Modifie l'attribut pathname
     * @param name chemin vers Multimedia
     */
    void setPathname(std::string pathname);

    /**
     * @brief affiche le Multimedia
     * @param ostream support d'affichage
     */
    virtual void print(std::ostream & ostream)const;

    /**
     * @brief Joue le Multimedia 
     */
    virtual void play() const = 0;
};

//smart pointer
using MultimediaPtr = std::shared_ptr<Multimedia>;

#endif