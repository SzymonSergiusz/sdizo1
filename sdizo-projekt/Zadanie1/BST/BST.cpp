//
//  BST.cpp
//  sdizo-projekt
//
//  Created by Szymon Kluska on 15/04/2023.
//
#include <fstream>
#include <random>

#include "BST.hpp"
#include <cmath>
#include <iostream>

BST::BST() :root(nullptr){};
BST::~BST() {};
void BST::rotateRight(TreeNode* A) {
    TreeNode* B = A->left;
    if (B == nullptr)
        return;
    TreeNode* parent = A->parent;
    A->left = B->right;
    if (A->left != nullptr) {
        A->left->parent = A;
    }
    B->right = A;
    B->parent = parent;
    A->parent = B;
    
    if (parent == nullptr) {
        root = B;
    } else {
        if (parent->left == A) {
            parent->left = B;
        } else {
            parent->right = B;
        }
    }
}

void BST::rotateLeft(TreeNode* A) {
    TreeNode* B = A->right;
    if (B == nullptr)
        return;
    TreeNode* parent = A->parent;
    A->right = B->left;
    if (A->right != nullptr) {
        A->right->parent = A;
    }
    B->left = A;
    B->parent = parent;
    A->parent = B;
    
    if (parent == nullptr) {
        root = B;
    } else {
        if (parent->left == A) {
            parent->left = B;
        } else {
            parent->right = B;
        }
    }
}

void BST::DSW(TreeNode* node) {
    int n = 0;
    TreeNode* parent = root;
    
    while (parent != nullptr) {
        if (parent->left != nullptr) {
            rotateRight(node);
            parent = parent->parent;
        }
        n++;
        parent = parent->right;
    }
    
    int s = n+1 - log2(n+1);
    parent = root;
    //todo ?
    for (int i = 1; i < s; i++) {
        rotateLeft(node);
        parent = parent->parent->right;
    }
    
    n = n-s;
    
    while (n > 1) {
        n = n/2;
        parent = root;
        for (int i = 1; i < n; i++) {
            parent = parent->parent->right;
        }
    }
}

void BST::insert(int value)  {
    root = insertNode(nullptr, root, value);
}

TreeNode* BST::insertNode(TreeNode *parent, TreeNode *node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insertNode(node, node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node, node->right, value);
    }
    
    return node;
}

bool BST::search(TreeNode* node, int s) {
    
    if (node == nullptr || s == root->value) {
        return node;
    }
    if (s < node->value) {
        return search(node->left, s);
    } else return search(node->right, s);
    
    return false;
}
TreeNode* BST::min(TreeNode *node) {
    TreeNode* min = node;
    while (min && min->left == nullptr) {
        min = min->left;
    }
    return min;
}

TreeNode* BST::deleteValue(TreeNode* node, int value) {
    if (node == nullptr)
        return node;
    
    if (value <node->value) {
        node->left = deleteValue(node->left, value);
    } else if (value > node->value) {
        node->right = deleteValue(node->right, value);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }

        TreeNode* temp = min(root->right);
         node->value = temp->value;
        node->right = deleteValue(node->right, temp->value);
    }
    return node;
}


void BST::displayTree() {
    print2DUtil(root, 4);
}

//print
void BST::print2DUtil(TreeNode* root, int space)
{
    int COUNT = 10;
    // Base case
    if (root == nullptr)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->value << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void BST::print2D(TreeNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
void BST::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    delete root;
    int newSize;
    inputFile >> newSize;
    
    std::cout << "new size " << newSize <<"\n";
    
    int value;
    if (inputFile.is_open()) {
        while (inputFile >> value) {
            insert(value);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
}

void BST::generateBST(int size) {
    delete root;
    
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, 100);
    
    for (int i = 0; i < size; i++) {
        insert(distr(rng));
    }
}
