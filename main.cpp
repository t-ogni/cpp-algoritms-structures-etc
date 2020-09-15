#include <iostream>
#include "sequrity/base64.h"
#include <string>

int main(){
    std::string k = "ok";
    while(k.size() > 0) {
        std::cin >> k;
        std::cout << base64().encode(k) << '\n'; //
    }
    return 0;
}