#ifndef Table_hpp
#define Table_hpp
#include <string>
#include <stdio.h>
class Table {
private:
    int size;
    int* data;

public:
    Table();
    ~Table();

    void add(int index, int val);
    void deleteByIndex(int index);
    void display();
    void generateTable(int size);
    int loadFromFile(std::string fileName);
    bool isContainingValue(int val);
    int getSize();
};
#endif /* Table_hpp */
