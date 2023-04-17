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

void BST::deleteRoot() {
    root = nullptr;
}

void BST::rotateRight(TreeNode *&root, TreeNode *&A) {
    TreeNode* B = A->left;
    A->left = B->right;
    B->right = A;
    root->right = B;
    A = B;
}

 
int BST::treeToSpine(TreeNode* root)
{
    int nodeCount = 0;
    TreeNode* nodeA = root->right;
 
    while (nodeA != nullptr) {
        
        //rotacja w prawo jeśli istnieje lewy węzeł
        if (nodeA->left != nullptr) {
            rotateRight(root, nodeA);
        } else {
            //dalsze przejście w dół drzewa
            nodeCount++;
            root = nodeA;
            nodeA = nodeA->right;
        }
    }
    return nodeCount;
}

void BST::compress(TreeNode* root, int m) {
    TreeNode* scanner = root;

    //przekształcenie w drzewo
    for (int i = 0; i < m; i++) {
        TreeNode* child = scanner->right;
        scanner->right = child->right;
        scanner = scanner->right;
        child->right = scanner->left;
        scanner->left = child;
        
    }
}
 
TreeNode* BST::balanceBST(TreeNode* root) {
    //pusty węzeł
    std::unique_ptr<TreeNode> emptyNode(new TreeNode(0));
    emptyNode->right = root;
 
    int nodesCount = treeToSpine(emptyNode.get());
 
    int logarytm = log2(nodesCount + 1);
 
    int m = pow(2, logarytm) - 1;
    //kompresja liści
    compress(emptyNode.get(), nodesCount - m);

    m = m /2;
    while (m > 0) {
        compress(emptyNode.get(), m);
        m = m / 2;
    }
    
    return emptyNode->right;
}


void BST::DSW() {
    root = balanceBST(root);
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
    
    if (node == nullptr) {
        return false;
    } else if (s == node->value) {
        return true;
    } else if (s < node->value) {
        return search(node->left, s);
    } else
        return search(node->right, s);
}

TreeNode* BST::minimumTreeNode(TreeNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


void BST::deleteValue(TreeNode* node, int value) {
    TreeNode* parent = nullptr;
    TreeNode* current = node;
    
    //znalezienie węzła do usunięcia
    while (current != nullptr && current->value != value) {
        parent = current;
        if (value > current->value) {
            current = current->right;
        } else current = current->left;
    }
    //nie ma wartoście w drzewie
    if (current == nullptr) return;
    
    //węzęł nie ma synów
    if (current->left ==  nullptr && current->right == nullptr) {
        //nie ma synów i ojca -> korzeń
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else parent->right = nullptr;
        delete current;
        return;
    }
    //jeden syn
    else if (current->left == nullptr || current->right == nullptr) {
        TreeNode* child = nullptr;
        if (current->left != nullptr) {
            child = current->left;
        } else child = current->right;
        
        //jeśli węzeł nie ma ojca => korzeń do usunięcia
        if (parent == nullptr) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else parent->right = child;
        return;
    }
    //dwóch synów
    else {
        
        TreeNode* successor = minimumTreeNode(current->right);
        if (successor != nullptr) {
            TreeNode* successorParent = successor->parent;
            //zamiana wartości
            current->value = successor->value;
            //usunięcie następnika
            if (successorParent != nullptr) {
                if (successorParent->left == successor) {
                    successorParent->left = successor->right;
                } else {
                    successorParent->right = successor->right;
                }
                delete successor;
            }
        }
    }
    
}



void BST::displayTree() {
    print2DUtil(root, 4);
}

//print
void BST::print2DUtil(TreeNode* root, int space)
{
    int COUNT = 8;
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
    root = nullptr;
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
    root = nullptr;
    
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, 100);
    
    for (int i = 0; i < size; i++) {
        insert(distr(rng));
    }
}
