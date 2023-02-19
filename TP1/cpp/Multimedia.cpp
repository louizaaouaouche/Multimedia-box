/**
 * @file Multimedia.cpp
 * @author Louiza AOUAOUCHE
 */
#include "Multimedia.h"

Multimedia::Multimedia(){

}
Multimedia::Multimedia(std::string name , std::string pathname){
    this->name = name;
    this->pathname = pathname;
}

Multimedia::~Multimedia(){}

std::string Multimedia::getName()const{
    return this->name;
}
std::string Multimedia::getPathname()const{
    return this->pathname;
}

void Multimedia::setName(std::string name){
    this->name = name;
}
void Multimedia::setPathname(std::string pathname){
    this->pathname = pathname;
}

void Multimedia::print(std::ostream & s)const{
    s << " Name:"  << this->name << ". Pathname: "<< this->pathname;//<< std::endl;
}