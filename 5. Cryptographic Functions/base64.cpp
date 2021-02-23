//______  _______ _______ _______ _______ _______
//|     \ |______    |    |______ |_____| |  |  |
//|_____/.______| .  |    |______ |     | |  |  |
// Copyright (c) 2020 Dark Shield Team. All rights reserved.
// Created by moonlin on 007 07.09.20 at 21:35.

#include "base64.h"
#include <string>

base64::base64() = default;

std::string base64::encode(std::string const &in){
    int appendSize = in.length() % 3 == 1 ? 2 :
                        in.length() % 3 == 2 ? 1 : 0;
    unsigned int clearSize = (unsigned int) in.length() - in.length() % 3;
    int length = (int)((in.length() * 8) / 6 + appendSize*4);   // 8 and 6 are bits in output

    std::string result;
    result.reserve(length);

    for (int i = 0; i < (int)clearSize; i+=3) {
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

inline bool is_b64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64::decode(std::string const &in){
    unsigned int in_len = in.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char inputArray[4];
    unsigned char outputArray[3];
    std::string ret;

    while (in_len-- && ( in[in_] != '=') && is_b64(in[in_]))
    {
        inputArray[i++] = in[in_];
        in_++;
        if (i == 4)
        {
            for (i = 0; i < 4; i++)
                inputArray[i] = table.find(inputArray[i]);

            outputArray[0] = (inputArray[0] << 2) + ((inputArray[1] & 0b00110000) >> 4);
            outputArray[1] = ((inputArray[1] & 0b00001111) << 4) + ((inputArray[2] & 0b00111100) >> 2);
            outputArray[2] = ((inputArray[2] & 0b00000011) << 6) + inputArray[3];

            for (i = 0; (i < 3); i++)
                ret += outputArray[i];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j <4; j++)
            inputArray[j] = 0;

        for (j = 0; j <4; j++)
            inputArray[j] = table.find(inputArray[j]);

        outputArray[0] = ( inputArray[0] << 2) + ((inputArray[1] & 0b00110000) >> 4);
        outputArray[1] = ((inputArray[1] & 0b00001111) << 4) + ((inputArray[2] & 0b00111100) >> 2);
        outputArray[2] = ((inputArray[2] & 0b00000011) << 6) + inputArray[3];

        for (j = 0; (j < i - 1); j++)
            ret += outputArray[j];
    }

    return ret;
}

base64::~base64() = default;