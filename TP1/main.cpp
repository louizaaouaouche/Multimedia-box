//
// main.cpp
// Created on 13/12/2022
//

#include <iostream>
#include "./headers/Multimedia.h"
#include "./headers/Photo.h"
#include "./headers/Video.h"
using namespace std;


int main(int argc, const char* argv[]){

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

    
    return 0;   

}
