#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node {
private:
    int key;
    Node* next;
    Node* previous;
    
public:
    Node(int key);
    ~Node();
    
    int getKey() {
        return key;
    };
    
    Node* getNext() {
        return next;
    }
    
    Node* getPrevious() {
        return previous;
    }
    
    void setPrevious(Node* newNode) {
        previous = newNode;
    }
    
    void setNext(Node* newNode) {
        next = newNode;
    }
};

#endif /* Node_hpp */
