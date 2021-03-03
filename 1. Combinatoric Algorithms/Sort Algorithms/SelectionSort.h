//
// Created by moonlin on 01.03.2021.
// selection sort: O(n^2)

#ifndef MAIN_SELECTIONSORT_H
#define MAIN_SELECTIONSORT_H

template <class T>
void selectionSort(T *dataStart, T *dataEnd){
    for (T *data = dataStart; data <= dataEnd; data++) {
        T *min = data;
        for (T *check = data + 1; check <= dataEnd; check++) {
            if(*min > *check)
                min = check;
        }
        T temp = *data;
        *data = *min;
        *min = temp;
    }
}

#endif //MAIN_SELECTIONSORT_H
