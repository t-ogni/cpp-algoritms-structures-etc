#include "insertionSort.h"

void insertionSort(int *mas, int length){
    for (int i = 1; i < length; ++i) {
        int n = i;
        while(mas[n-1] > mas[n] && n != 0){
            mas[n-1] +=  mas[n]; // flip variables
            mas[n] =  mas[n-1] -  mas[n];
            mas[n-1] -=  mas[n];
            n--;
        }
    }
}
void insertionSort(double *mas, int length){
    for (int i = 1; i < length; ++i) {
        int n = i;
        while(mas[n-1] > mas[n] && n != 0){
            mas[n-1] +=  mas[n]; // flip variables
            mas[n] =  mas[n-1] -  mas[n];
            mas[n-1] -=  mas[n];
            n--;
        }
    }
}

void insertionSort(float *mas, int length){
    for (int i = 1; i < length; ++i) {
        int n = i;
        while(mas[n-1] > mas[n] && n != 0){
            mas[n-1] +=  mas[n]; // flip variables
            mas[n] =  mas[n-1] -  mas[n];
            mas[n-1] -=  mas[n];
            n--;
        }
    }
}
