#include <iostream>
#include <fstream>
#include "MaxHeap.hpp"
#include <random>
using namespace std;

MaxHeap::MaxHeap(): heapSize(0), heapLength(0), data(new int[0]){
    
}
MaxHeap::~MaxHeap() {}

void MaxHeap::add(int item) {
    if (heapSize == heapLength) {
        std::cout << "Osiągnięto limit kopca";
        return;
    }
    
    data[heapSize] = item;
    int i = heapSize;
    while (i > 0 && data[parent(i)] < data[i]) {
        swap(i, parent(i));
        i = parent(i);
    }
    heapSize++;
}
void MaxHeap::maxHeapify(int i) {
    
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && data[l] > data[i]) {
        largest = l;
    }
    if (r < heapSize && data[r] > data[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(i, largest);
        maxHeapify(largest);
    }
}
void MaxHeap::deleteByIndex(int i) {
    if (i < 0 || i >= heapSize) {
         std::cout << "Nieprawidłowy indeks\n";
         return;
     }

     data[i] = data[heapSize-1];
     heapSize--;
    maxHeapify(i);
}

bool MaxHeap::search(int el) {
    for (int i = 0; i < heapSize; i++) {
        if (data[i] == el) {
            return true;
        }
    }
    return false;
}
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
void MaxHeap::displayHeap() {
    int i = 0;

    while (i < heapSize) {
        std::cout << data[i] << " ";
        i++;
    }
    std::cout<<std::endl;
}


void MaxHeap::swap(int index1, int index2) {
        int temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
}
void MaxHeap::displayTable() {
    int i = 0;

    while (i < heapLength) {
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

void MaxHeap::generateHeap(int size) {
    if (heapSize != 0) {
        heapSize = 0;
        delete[] data;
        heapLength = size + 5;
        data = new int[heapLength];
    } else {
        heapLength = size + 5;
    }
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, 100);
    
    for (int i = 0; i < size; i++) {
        add(distr(rng));
    }
}

void MaxHeap::displayTree() {
    printHeap(data, heapSize);
}
#include <cmath>
#include <iomanip>

using namespace std;

void MaxHeap::printHeap(int heap[], int size)
{
    int height = log2(size) + 1;
    int index = 0;

    for (int i = 1; i <= height; i++) {
        int numNodes = pow(2, i - 1);
        int spaces = pow(2, height - i) - 1;

        cout << setw(spaces) << "";

        for (int j = 0; j < numNodes && index < size; j++) {
            cout << setw(2) << heap[index];
            cout << setw(spaces) << "";

            index++;

            if (j != numNodes - 1) {
                cout << setw(spaces) << "";
            }
        }

        cout << endl;
    }
}
