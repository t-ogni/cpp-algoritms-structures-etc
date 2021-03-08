//
// Created by moonlin on 06.03.2021.
//

#ifndef CPP_FILES_BURROWSWHEELERTRANSFORM_H
#define CPP_FILES_BURROWSWHEELERTRANSFORM_H

#include <vector>
#include <string>

const char ETX = '$'; // 0x02;

void rotate(std::string &st) {
    char first = *st.begin();
    for (auto i = st.begin(); i < st.end(); ++i)
        *(i) = *(i+1);

    *(st.end()-1) = first;
}

void sort(std::vector<std::string> &table){
    for(auto block = table.begin(); block < table.end()-1; block++){
        for(auto next = block + 1; next < table.end(); next++){
            if (*block > *next){ // minToMax -  inverse operator to change sides
                auto temp = *block;
                *block = *next;
                *next = temp;
            }
        }
    }
}
std::string BWT (std::string &inp){
    for (char c : inp)
        if (c == ETX)
            throw std::runtime_error("Input can't contain ETX");

    std::string input;
    input += inp;
    input += ETX;

    std::vector<std::string> table;
    for (size_t i = 0; i < input.length(); i++) {
        table.push_back(input);
        rotate(input);
    }

    sort(table);

    std::string out;
    for(auto str : table)
        out += str[str.length() - 1];

    return out;
}

std::string BWTdecode(std::string &inp){
//    int pos = 0;
//    for(auto c : inp)
//        if(c == ETX) break;
//        else pos++;

    std::vector<std::string> table(inp.size());
    for (int i = 0; i < inp.size(); i++) {
        for (int j = 0; j < inp.size(); j++) {
            table[j] = inp[j] + table[j];
        }
        sort(table);
    }
    for(auto s : table)
        if(*(s.end()-1) == ETX){
            s.pop_back();
            return s;
        }
    return table[0];
}

#endif //CPP_FILES_BURROWSWHEELERTRANSFORM_H
