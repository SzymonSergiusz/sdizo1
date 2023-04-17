//
//  RedBlackTree.hpp
//  sdizo-projekt
//
//  Created by Szymon Kluska on 17/04/2023.
//

#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp

#include <stdio.h>

struct RBTNode {
    RBTNode* parent;
    RBTNode* left;
    RBTNode* right;
    int value;
    char color;
    
    RBTNode(int x) : value(x), left(nullptr), right(nullptr){};
};

class RedBlackTree {
    
private:
    RBTNode root;
    
    
    void insert();
    void deleteValue(); //todo?
    void displayAsTree();
    void search();
    
    
    //funkcje do drzewa
    
    
    
    //inne
    void generate();
    void loadFromFile();
    
};

#endif /* RedBlackTree_hpp */
