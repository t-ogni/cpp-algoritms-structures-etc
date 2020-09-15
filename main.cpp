#include <iostream>
#include "sequrity/base64.h"
#include <string>

int main(){
    std::string k = "ok";
    while(k.size() > 0) {
        char kk[99];
        std::cin.getline(kk, 99);
        k = kk;
        k = base64().encode(k);
        std::cout << k << '\n' << base64().decode(k) << '\n'; //
    }
    return 0;
}