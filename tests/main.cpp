#include <iostream>
#include "insertionSort.h"

int main(){
    int mas[] = {3, 45, -4, 6, 0, -3, 2};
    insertionSort(mas, sizeof(mas) / sizeof(mas[0]));
    for (auto i : mas){
        std::cout << i << std::endl;
    }
    return 0;
}