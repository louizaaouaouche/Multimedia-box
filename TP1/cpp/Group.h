/**
 * @file Group.h
 * @author Louiza AOUAOUCHE
 */
#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include <iostream>
#include "Multimedia.h"


/**
 * @brief Classe Groupe heritant de liste de pointeurs vers Multimedia
 */
class Group : public std::list<MultimediaPtr>{
friend class Managing;
private :
    std::string name ;
    
public:
    /**
     * @brief Constructeur par défaut du groupe
     */
    Group() : name("Groupe"){}

    /**
     * @brief Constructeur de la classe groupe
     * @param name_
     */
    Group(std::string name_){
        name = name_;
    }

    /**
     * Destructeur de groupe
     */
    ~Group(){
        std::cout << "Suppression du groupe " << getName() << " - ok" << std::endl;
    }

    /**
     * @brief getName
     * @return
     */
    std::string getName(){
        return name;
    }

    /**
     * @brief méthode d'affichage
     * @details affiche les attributs des objets du groupe
     * @param ostream
     */
    void printGroup(std::ostream &ostream){
        ostream << "-- Affichage du groupe : " << name;
        for (auto i = this->begin() ; i != this->end() ; i++ ){
            (*i) -> print(ostream);
        }
    }
};

//smart pointer
using GroupPtr = std::shared_ptr<Group>;

#endif // GROUP_H