//
//  Heap.hpp
//  SDIZO
//
//  Created by Szymon Kluska on 08/04/2023.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp
#include <string>
#include <stdio.h>
class MaxHeap {
private:
    int heapSize; //liczba elementów kopca
    int heapLength; //liczba elementów w tablicy
    int* data; //tablica
public:
    MaxHeap();
    
    void setLength(int n);

    ~MaxHeap();
    
    void add(int item);
    void deleteByIndex(int i);
    void maxHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    bool search(int el);
    

    void swap(int index1, int index2);
    void displayTable();
    void displayHeap();
    void displayTree();
    void generateHeap(int size);
    void loadFromFile(std::string fileName);
};
#endif /* Heap_hpp */

//
