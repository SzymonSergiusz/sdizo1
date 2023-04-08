#include <iostream>
#include <fstream>
#include <random>
#include "Table.hpp"
Table::Table() :data(new int[0]), size(0) {}

Table::~Table() {
    delete[] data;
}

void Table::add(int index, int val) {
    int newSize = size+1;
    int* newData = new int[newSize];

    int i = 0;
    int j = 0;
    while (i < newSize) {
        if (i == index) {
            *(newData+i) = val;
        } else {
            *(newData+i) = *(data+j);
            newData[i] = data[j];
            j++;
        }
        i++;
    }

    delete[] data;
    data = newData;
    size = newSize;
}

void Table::deleteByIndex(int index) {
    int newSize = size-1;
    int* newData = new int[newSize];

    int i = 0;
    int j = 0;
    while (j < newSize) {
        if (i != index) {
            *(newData+j) = *(data+i);
            j++;
        }
        i++;
    }

    delete[] data;
    data = newData;
    size = newSize;
}


bool Table::isContainingValue(int val) {
    int i = 0;
    while (i < size) {
        if (*(data+i) == val) {
            return true;
        }
        i++;
    }
    return false;
}

void Table::display() {
    int i = 0;

    while (i < size) {
        std::cout << *(data+i) << " ";
        i++;
    }
    std::cout<<std::endl;
}

int Table::getSize() {return size;}

int Table::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    int newSize;
    inputFile >> newSize;
//    std::cout << "new size " << newSize <<"\n";
    if (size != 0) {
        size = 0;
        delete[] data;
        data = new int[0];
    }


    
    if (inputFile.is_open()) {
        int number;
        int i = 0;
        while (inputFile >> number) {
//            std::cout << i << " : " << number << std::endl;
            add(i, number);
            i++;
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
        return -1;
    }
    
    return 0;
}
void Table::generateTable(int size) {
    
    if (this->size != 0) {
        this->size = 0;
        delete[] data;
        data = new int[0];
    }
    
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, 100);
    
    for (int i = 0; i < size; i++) {
        add(i, distr(rng));
    }
}
