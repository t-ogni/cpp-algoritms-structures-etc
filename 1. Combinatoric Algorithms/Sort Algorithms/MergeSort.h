//
// Created by moonlin on 02.03.2021.
//

#ifndef CPP_FILES_MERGESORT_H
#define CPP_FILES_MERGESORT_H

template <class T> // for declaration new function
void merge(T *dataStart, T *middle, T *dataEnd);

template <class T>
void mergeSort(T *dataStart, T *dataEnd){
    if(dataEnd == dataStart) return; // massive with one value amounts sorted massive
    T *mid = dataStart + ((dataEnd - dataStart) / 2);
    mergeSort(dataStart, mid); // sort left side
    mergeSort(mid + 1, dataEnd); // sort right side
    merge(dataStart, mid, dataEnd); // merge two sorted sides
}

template <class T>
void merge(T *dataStart, T *middle, T *dataEnd){
    int size = (dataEnd - dataStart) + 1;
    T *merged = new T[size]; // template massive with merged data
    size_t current = 0;  // current pushing cell
    T *lPointer = dataStart; // left iterator
    T *rPointer = middle + 1; // right iterator

    // merge minimum value until one of iters would reach end
    while (lPointer <= middle && rPointer <= dataEnd) {
        if(*lPointer < *rPointer) {
            merged[current++] = *lPointer;
            lPointer++;
          } else {
            merged[current++] = *rPointer;
            rPointer++;
          }
    }

    // add remaning data
    while (lPointer <= middle) {
        merged[current++] = *lPointer;
        lPointer++;
    }

    while (rPointer <= dataEnd) {
        merged[current++] = *rPointer;
        rPointer++;
    }

    // copy template mas to base data cells
    std::copy(std::make_move_iterator(merged),
              std::make_move_iterator(&merged[size]),
              dataStart);
  }

#endif //CPP_FILES_MERGESORT_H
