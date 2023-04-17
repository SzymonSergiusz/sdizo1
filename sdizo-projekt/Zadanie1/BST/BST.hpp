//
//  BST.hpp
//  sdizo-projekt
//
//  Created by Szymon Kluska on 15/04/2023.
//

#ifndef BST_hpp
#define BST_hpp
#include <fstream>

#include <stdio.h>

struct TreeNode {
    int value;
    TreeNode* parent;
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
    TreeNode* getRoot() {
        return root;
    }
    
    void rotateRight(TreeNode* &root, TreeNode* &A);
    void rotateLeft(TreeNode* &root, TreeNode* &A);
    void DSW();
    
    TreeNode* balanceBST(TreeNode* root);
    int treeToSpine(TreeNode* root);
    void compress(TreeNode* root, int m);
    void deleteRoot();
    void deleteValue(TreeNode* node, int value);
    
    bool search(TreeNode* node, int s);
    
    TreeNode* insertNode(TreeNode *parent, TreeNode* node, int value);
    TreeNode* minimumTreeNode(TreeNode* node);
    
    void generateBST(int size);
    void displayTree();
    void loadFromFile(std::string fileName);
    //print
    void print2DUtil(TreeNode* root, int space);
    void print2D(TreeNode* root);
};
#endif /* BST_hpp */
