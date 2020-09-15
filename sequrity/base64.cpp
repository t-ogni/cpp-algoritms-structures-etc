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
    int clearSize = in.length() - in.length() % 3;
    int length = (int)((in.length() * 8) / 6 + appendSize*4);   // 8 and 6 are bits in output

    std::string result;
    result.reserve(length);

    for (int i = 0; i < clearSize; i+=3) {
        result.push_back(this-> table[(in[i] >> 2)]);
        result.push_back(this-> table[((in[i] & 0b00000011) << 4 | in[i+1] >> 4)]);
        result.push_back(this-> table[((in[i+1] & 0b00001111) << 2 | in[i+2] >> 6)]);
        result.push_back(this-> table[(in[i+2] & 0b00111111)]);
    }

    switch(appendSize){
        case 2:
            result.push_back(this-> table[(in[in.length()-1] >> 2)]);
            result.push_back(this-> table[((in[ in.length()-1] & 0b00000011) << 4)]);
            result.push_back('=');
            result.push_back('=');
            break;
        case 1:
            result.push_back(this-> table[(in[in.length()-2] >> 2)]);
            result.push_back(this-> table[(((in[ in.length()-2] & 0b00000011) << 4) | (in[in.length()-1] >> 4))]);
            result.push_back(this -> table[((in[in.length()-1] & 0b00001111) << 2)]);
            result.push_back('=');
            break;
        default:
            break;
    }
    return result;
}

std::string base64::decode(std::string const &in){

    return in;
}

base64::~base64() = default;