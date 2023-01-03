#include "Multimedia.h"

//Constructeurs
Multimedia::Multimedia(){

}
Multimedia::Multimedia(std::string name , std::string pathname){
    this->name = name;
    this->pathname = pathname;
}

//Destructeur
Multimedia::~Multimedia(){}

//Getters
std::string Multimedia::getName()const{
    return this->name;
}
std::string Multimedia::getPathname()const{
    return this->pathname;
}

//Setters
void Multimedia::setName(std::string name){
    this->name = name;
}
void Multimedia::setPathname(std::string pathname){
    this->pathname = pathname;
}

//Afficheur
void Multimedia::print(std::ostream & s)const{
    s << "Name:"  << this->name << ". Pathname: "<< this->pathname << std::endl;
}