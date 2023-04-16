//
//  BST.hpp
//  sdizo-projekt
//
//  Created by Szymon Kluska on 15/04/2023.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(NULL), right(NULL){};
};

class BST {
private:
    TreeNode* root;
public:

    BST();
    ~BST();
    
    void insert(int value);
    
    TreeNode* insertNode(TreeNode* node, int value);
    
    
};
#endif /* BST_hpp */
