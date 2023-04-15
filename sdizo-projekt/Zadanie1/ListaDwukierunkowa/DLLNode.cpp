#include "DLLNode.hpp"
DLLNode::DLLNode(int key) : key(key), next(nullptr), previous(nullptr) {}
DLLNode::~DLLNode() {
//    delete[] next;
//    delete[] previous;
}
