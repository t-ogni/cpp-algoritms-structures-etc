//
// Created by moonlin on 01.03.2021.
// bubble sort: O(n^2)

#ifndef MAIN_BUBBLESORT_H
#define MAIN_BUBBLESORT_H

template <class T>
void bubbleSort(T *dataStart, T *dataEnd, bool minToMax = true){
//    assert(dataStart >= dataEnd);
    for(T *block = dataStart; block < dataEnd; block++){
        for(T *next = block + 1; next <= dataEnd; next++){
            if (minToMax ? *block > *next : *block < *next){
                T temp = *block;
                *block = *next;
                *next = temp;
            }
        }
    }
}


#endif //MAIN_BUBBLESORT_H
