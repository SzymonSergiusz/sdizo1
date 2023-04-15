//
//  Heap.cpp
//  SDIZO
//
//  Created by Szymon Kluska on 08/04/2023.
//
#include <iostream>
#include <fstream>
#include "MaxHeap.hpp"
//kopiec binarny max
MaxHeap::MaxHeap() : heapSize(0), heapLength(0), data(new int[0]){
    
}
//MaxHeap::MaxHeap() : heapSize(0), heapLength(5), data(new int[heapLength]){
//
//}
MaxHeap::~MaxHeap() {}

void MaxHeap::setLength(int n) {
    heapLength = n;
    data = new int[heapLength];
}

int MaxHeap::parent(int i) {
    return (i-1)/2;
}
int MaxHeap::left(int i) {
    return 2*i+1;
}
int MaxHeap::right(int i) {
    return 2*i+2;
}

void MaxHeap::add(int item) {
    if (heapSize == heapLength) {
        std::cout << "Osiągnięto limit kopca";
        return;
    }
    
    data[heapSize] = item;

    int i = heapSize;
    heapSize++;
    if (i < heapSize) {
        maxHeapify(i);
    }
    
}

void MaxHeap::swap(int index1, int index2) {
    if (index1 < heapSize && index2 < heapSize) {
        
        int temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }
}

void MaxHeap::maxHeapify(int i) {
    
    int l = left(i);
    int r = right(i);
    int largest;

    if (l < heapSize && data[l] > data[i]) {
        largest = l;
    } else largest = i;
    if (r < heapSize && data[r] > data[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(i, largest);
        maxHeapify(largest);
    }
}

void MaxHeap::displayTable() {
    int i = 0;

    while (i < heapLength) {
        std::cout << data[i] << " ";
        i++;
    }
    std::cout<<std::endl;
}

void MaxHeap::displayHeap() {
    int i = 0;

    while (i < heapSize) {
        std::cout << data[i] << " ";
        i++;
    }
    std::cout<<std::endl;
}

void MaxHeap::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    delete[] data;
    int newSize;
    inputFile >> newSize;
    
    std::cout << "new size " << newSize <<"\n";
    heapSize = 0;
    heapLength = newSize+5;
    data = new int[heapLength];
    
    int number;
    if (inputFile.is_open()) {
        while (inputFile >> number) {
//            std::cout << i << " : " << number << std::endl;
            add(number);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
        
    }
}
