//
// Created by moonlin on 06.03.2021.
//

#ifndef CPP_FILES_BURROWSWHEELERTRANSFORM_H
#define CPP_FILES_BURROWSWHEELERTRANSFORM_H

#include <vector>
#include <string>

const char STX = '^'; // 0x02;

void rotate(std::string &st) {
    char first = *st.begin();
    for (auto i = st.begin(); i < st.end(); ++i)
        *(i) = *(i+1);

    *(st.end()-1) = first;
}

std::string BWT (std::string &inp){
    for (char c : inp)
        if (c == STX)
            throw std::runtime_error("Input can't contain STX");

    std::string input;
    input += STX;
    input += inp;

    std::vector<std::string> table;
    for (size_t i = 0; i < input.length(); i++) {
        table.push_back(input);
        rotate(input);
    }
    for(auto block = table.begin(); block < table.end()-1; block++){
        for(auto next = block + 1; next < table.end(); next++){
            if (*block > *next){ // minToMax -  inverse operator to change sides
                auto temp = *block;
                *block = *next;
                *next = temp;
            }
        }
    }

    std::string out;
    for(auto str : table)
        out += str[str.length() - 1];

    return out;
}

#endif //CPP_FILES_BURROWSWHEELERTRANSFORM_H
