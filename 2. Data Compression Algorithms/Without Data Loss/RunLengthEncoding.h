//
// Created by moonlin on 03.03.2021.
//

#ifndef CPP_FILES_RUNLENGTHENCODING_H
#define CPP_FILES_RUNLENGTHENCODING_H

#include <string>

std::string RLEcompress(const std::string& data) {
    std::string out;
    for(auto c = data.begin(); c < data.end(); c++){
        size_t total = 1;
        while (*c == *(c + 1)){
            total++;
            c++;
        }
        out.append(std::to_string(total));
        out.push_back(*c);
    }
    return out;
}

#endif //CPP_FILES_RUNLENGTHENCODING_H
