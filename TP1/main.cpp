//
// main.cpp
// Created on 13/12/2022
//

#include <iostream>
#include <vector>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
using namespace std;


int main(int argc, const char* argv[]){
    /*
    //PART 1 to 4
    Multimedia *media1 = new Multimedia();
    Multimedia *media2 = new Multimedia("image" , "image.png");
    
    media1->setName("image2");
    media1->setPathname("image2.png");

    media1->print(std::cout);
    media2->print(std::cout);
    
    Photo *photo1 = new Photo("photo1","photo.png", 3, 4);
    photo1->print(std::cout);

    Video *video1 = new Video("video1","video.png", 3);
    video1->setDuration(4);
    video1->print(std::cout);
    */
    
    //PART 5

    std::vector<Multimedia *> listMultimedia;
    listMultimedia.push_back(new Photo("Photo1", "src/", 5, 10));
    listMultimedia.push_back(new Video("Video1", "src/home/", 3));
    listMultimedia.push_back(new Video("Video2", "src/", 4));
    
    for(int i(0); i<listMultimedia.size(); ++i){
        listMultimedia[i]->play(); //lancer le i-ème média de la liste
    }
    
    return 0;   

}
