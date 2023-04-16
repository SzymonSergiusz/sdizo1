//
//  BST.cpp
//  sdizo-projekt
//
//  Created by Szymon Kluska on 15/04/2023.
//

#include "BST.hpp"
BST::BST() :root(nullptr){};

void BST::insert(int value)  {
    root = insertNode(root, value);
}

TreeNode* BST::insertNode(TreeNode *node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}
