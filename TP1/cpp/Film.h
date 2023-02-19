/**
 * @file Film.h
 * @author Louiza AOUAOUCHE
 */
#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include <memory>
#include "Video.h"

/**
 * @brief Classe Film heritant de la classe Video
 */
class Film : public Video{
friend class Managing;

private :
    int length = 0 ; //le nombre de chapitres du film
    int * tabDurations = new int[length];//Tableau contenant la durée de chacun des chapitre

public:
    /**
     * @brief Constructeur par défaut de l'objet Film
     */
    Film(){}

    /**
     * @brief Constructeur d'un nouvel objet Film
     * @param name nom du film
     * @param fileName chemin vers le film
     * @param duration duree totale du film
     * @param length_ nombre de chapitres
     * @param tabDurations_ duree de chacun des chapitres
     */
    Film(std::string name, std::string fileName,int duration, int length_, const int * tabDurations_) : Video(name,fileName,duration){
        length = length_;
        this->setTabDurations(tabDurations_,length_);
    }

    /**
     * @brief Destructeur de Film
     */
    ~Film(){
        delete[] tabDurations;
    }

    /**
     * @brief getter du tableau de durées
     * @return const int* 
     */
    const int * getTabDurations() const;

    /**
     * @brief getter du nombre de chapitres
     * @return int* 
     */
    int * getLength() const;

    /**
     * @brief Setter de la durée des chapitres
     * @param tabDurations_ 
     * @param length_ 
     */
    void setTabDurations( const int* tabDurations_ , int length_);

    /**
     * @brief setter de l'attribut length
     * @param length_ 
     */
    void setLength( int length_);

    
    /**
     * @brief display affiche les variables du film
     * @param flux 
     */
    void print(std::ostream & ostream) const;

    /**
     * @brief crée une copie du tableau 
     * @param tab 
     * @param size 
     * @return int* 
     */
    int * copyTab(const int *tab, int size) const;


};

//smart pointer
using FilmPtr = std::shared_ptr<Film>;

#endif // FILM_H