#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <iostream>
#include <algorithm> // для std::swap

template<typename T>
typename std::enable_if<std::is_base_of<Person, T>::value>::type
bubbleSortInc(std::vector<T>& arr, std::string mode){
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            bool shouldSwap = false;
            if (mode == "i") {
                shouldSwap = arr[j].getId() > arr[j + 1].getId();
            } else if (mode == "n") {
                shouldSwap = arr[j].getName() > arr[j + 1].getName();
            } else if (mode == "sn") {
                shouldSwap = arr[j].getSurname() > arr[j + 1].getSurname();
            } else if (mode == "ag") {
                shouldSwap = arr[j].getAge() > arr[j + 1].getAge();
            } else if (mode == "s") {
                shouldSwap = arr[j].getSex() > arr[j + 1].getSex();
            } else if (mode == "ad") {
                shouldSwap = arr[j].getAddress() > arr[j + 1].getAddress();
            }
            if (shouldSwap) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    std::cout << "Sorting is completed!\n";
}

template<typename T>
void bubbleSortDec(std::vector<T>& arr, std::string mode) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            bool shouldSwap = false;
            if (mode == "i") {
                shouldSwap = arr[j].getId() < arr[j + 1].getId();
            }else if (mode == "n") {
                shouldSwap = arr[j].getName() < arr[j + 1].getName();
            }else if (mode == "sn") {
                shouldSwap = arr[j].getSurname() < arr[j + 1].getSurname();
            }else if (mode == "ag") {
                shouldSwap = arr[j].getAge() < arr[j + 1].getAge();
            }else if (mode == "s") {
                shouldSwap = arr[j].getSex() < arr[j + 1].getSex();
            }else if (mode == "ad") {
                shouldSwap = arr[j].getAddress() < arr[j + 1].getAddress();
            }
            if (shouldSwap) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    std::cout << "Sorting is completed!\n";
    std::cin.get();
    return;
}

#endif // BUBBLESORT_H
