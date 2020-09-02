// Created by User on 003 03.09.20 .
//

#include "bubbleSort.h"


void bubbleSort(int *mas, int length){
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length - j - 1; ++i) {
            if (mas[i] > mas[i+1]) {
                mas[i] ^= mas[i + 1] ^= mas[i] ^= mas[i + 1]; // flip variables

            }
        }
    }
}

void inbubbleSort(double *mas, int length) {
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length - j - 1; ++i) {
            if (mas[i] > mas[i+1]) {
                mas[i] += mas[i+1]; // flip variables
                mas[i+1] = mas[i] - mas[i+1];
                mas[i] -= mas[i+1];
            }
        }
    }
}

void bubbleSort(float *mas, int length){
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length - j - 1; ++i) {
            if (mas[i] > mas[i+1]) {
                mas[i] += mas[i+1]; // flip variables
                mas[i+1] = mas[i] - mas[i+1];
                mas[i] -= mas[i+1];
            }
        }
    }
}
