/**
 * @file Film.cpp
 * @author Louiza AOUAOUCHE
 */
#include "Film.h"

int * Film::copyTab(const int *tab, int size) const{
    
    int * newTab = new int[size];

    for (int i=0; i< size;i++){
        newTab[i]= tab[i];
    }
    return newTab;
}

const int * Film::getTabDurations() const {
    return copyTab(tabDurations,length);
}

void Film::setTabDurations( const int* tabDurations_ , int length_){
    length = length_;
    tabDurations = copyTab(tabDurations_,length_);
}

void Film::print(std::ostream & ostream) const{
    ostream << "Nombre de chapitres : " << length << " | " ;
    for (int i=0 ; i<length ; i++){
        ostream << "  Duree du chapitre numero " << i+1 << " = " << tabDurations[i] << " | ";
    }
}


