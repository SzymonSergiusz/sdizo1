#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class DLLNode {
private:
    int key;
    DLLNode* next;
    DLLNode* previous;
    
public:
    DLLNode(int key);
    ~DLLNode();
    
    int getKey() {
        return key;
    };
    
    DLLNode* getNext() {
        return next;
    }
    
    DLLNode* getPrevious() {
        return previous;
    }
    
    void setPrevious(DLLNode* newNode) {
        previous = newNode;
    }
    
    void setNext(DLLNode* newNode) {
        next = newNode;
    }
};

#endif /* Node_hpp */
