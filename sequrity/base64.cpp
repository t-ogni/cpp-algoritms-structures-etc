//______  _______ _______ _______ _______ _______
//|     \ |______    |    |______ |_____| |  |  |
//|_____/.______| .  |    |______ |     | |  |  |
// Copyright (c) 2020 Dark Shield Team. All rights reserved.
// Created by moonlin on 007 07.09.20 at 21:35.

#include "base64.h"
#include <string>
#include <iostream>

base64::base64() = default;

std::string base64::encode(std::string const &in){
    int appendSize = in.length() % 3 == 1 ? 2 :
                        in.length() % 3 == 2 ? 1 : 0;
    int len = in.length();
    int clearSize = in.length() - in.length() % 3;
    int length = (int)((in.length() * 8) / 6 + appendSize*6);   // 8 and 6 are bits in output

    std::string result;
    result.reserve(length);

    for (int i = 0; i < clearSize; i+=3) {
        (in[i] >> 2)
        (in[i] & 0b00000011) << 4 | in[i+1] >> 4)
        (in[i+1] & 0b00001111) << 2 | in[i+2] >> 6)
        (in[i+2] & 0b00111111)
    }
    switch(appendSize){
        case 0:
            std::cout << "0 rem\n";
            break;
        case 1:
            std::cout << "1 rem\n";
            break;
        case 2:
            std::cout << "2 rem\n";
            break;
    }
    return result;
}

std::string base64::decode(std::string const &in){

    return in;
}

base64::~base64() = default;