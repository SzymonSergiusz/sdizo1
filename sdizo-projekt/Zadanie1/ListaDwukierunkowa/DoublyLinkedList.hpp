#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include "DLLNode.hpp"


class DoublyLinkedList {
private:
    DLLNode* head;
    DLLNode* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void add(int key, int index);
    void deleteByValue(int val);
    void clear();
    
    bool isContainingValue(int val);
    
    void display();
    
    void loadFromFile(std::string fileName);
    
    void generateList(int size);
    
    int getSize() {
        return size;
    }
    
};


#endif /* DoublyLinkedList_hpp */
