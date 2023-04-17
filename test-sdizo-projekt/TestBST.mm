//
//  TestBST.m
//  test-sdizo-projekt
//
//  Created by Szymon Kluska on 16/04/2023.
//
#include <iostream>
#include <vector>
#include "BST.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <climits>
#include <sstream>
#import <XCTest/XCTest.h>

@interface TestBST : XCTestCase

@end

@implementation TestBST

-(void) testInsert {
       BST bst;
       bst.insert(5);
       bst.insert(10);
       bst.insert(1);
       bst.insert(7);
       bst.insert(2);
       TreeNode* root = bst.getRoot();
       XCTAssertTrue(root->value == 5, "Root should be 5");
       XCTAssertTrue(root->left->value == 1, "Left child of root should be 1");
       XCTAssertTrue(root->right->value == 10, "Right child of root should be 10");
       XCTAssertTrue(root->left->right->value == 2, "Right child of left child should be 2");
   }
-(void) testMin {
       BST bst;
       bst.insert(5);
       bst.insert(10);
       bst.insert(1);
       bst.insert(7);
       bst.insert(2);
    TreeNode* minimumNode = bst.minimumTreeNode(bst.getRoot());
    XCTAssertTrue(minimumNode->value==1);
   }
-(void) testDelete {
       BST bst;
       bst.insert(5);
       bst.insert(10);
       bst.insert(1);
       bst.insert(7);
       bst.insert(2);
       bst.deleteValue(bst.getRoot(), 5);
       TreeNode* root = bst.getRoot();
       XCTAssertTrue(root->value == 7, "Root should be 7");
       XCTAssertTrue(root->left->value == 1, "Left child of root should be 1");
       XCTAssertTrue(root->right->value == 10, "Right child of root should be 10");
       XCTAssertTrue(root->left->right->value == 2, "Right child of left child should be 2");
       bst.deleteRoot();
       XCTAssertTrue(bst.getRoot() == NULL, "Root should be NULL");
   }

-(void)  testSearch {
       BST bst;
       bst.insert(5);
       bst.insert(10);
       bst.insert(1);
       bst.insert(7);
       bst.insert(2);
       TreeNode* root = bst.getRoot();
       XCTAssertTrue(bst.search(root, 5) == true, "5 should be found in the BST");
       XCTAssertTrue(bst.search(root, 3) == false, "3 should not be found in the BST");
   }

//-(void)  testRotateRight {
//       BST bst;
//       bst.insert(5);
//       bst.insert(10);
//       bst.insert(1);
//       bst.insert(7);
//       bst.insert(2);
//       bst.rotateRight(bst.getRoot());
//       TreeNode* root = bst.getRoot();
//       XCTAssertTrue(root->value == 1, "Root should be 1");
//       XCTAssertTrue(root->right->value == 5, "Right child of root should be 5");
//       XCTAssertTrue(root->right->left->value == 2, "Left child of right child should be 2");
//       XCTAssertTrue(root->right->right->value == 10, "Right child of right child should be 10");
//   }
//
//-(void)  testRotateLeft {
//       BST bst;
//       bst.insert(5);
//       bst.insert(10);
//       bst.insert(1);
//       bst.insert(7);
//       bst.insert(2);
//       bst.rotateLeft(bst.getRoot());
//       TreeNode* root = bst.getRoot();
//       XCTAssertTrue(root->value == 10, "Root should be 10");
//       XCTAssertTrue(root->left->value == 5, "Left child of root should be 5");
//       XCTAssertTrue(root->left->left->value == 1, "Left child of left child should be 1");
//       XCTAssertTrue(root->left->right->value == 7, "Right child of left child should be 7");
//   }

@end
