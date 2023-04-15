#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include "Node.hpp"


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
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
