// Created by User on 003 03.09.20 .
//

#include "selectionSort.h"

void selectionSort(int *mas, int length){
    for (int i = 0; i < length; ++i) {
        int *min = &mas[i];
        for (int j = i; j < length; ++j) {
            if(*min > mas[j])
                min = &mas[j];
        }
        if(&mas[i] != min){
            mas[i] += *min; // flip variables
            *min = mas[i] - *min;
            mas[i] -= *min;
        }
    }
}

void selectionSort(double *mas, int length){
    for (int i = 0; i < length; ++i) {
        double *min = &mas[i];
        for (int j = i; j < length; ++j) {
            if(*min > mas[j])
                min = &mas[j];
        }
        if(&mas[i] != min){
            mas[i] += *min; // flip variables
            *min = mas[i] - *min;
            mas[i] -= *min;
        }
    }
}

void selectionSort(float *mas, int length){
    for (int i = 0; i < length; ++i) {
        float *min = &mas[i];
        for (int j = i; j < length; ++j) {
            if(*min > mas[j])
                min = &mas[j];
        }
        if(&mas[i] != min){
            mas[i] += *min; // flip variables
            *min = mas[i] - *min;
            mas[i] -= *min;
        }
    }
}

