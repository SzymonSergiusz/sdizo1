#include "Node.hpp"
Node::Node(int key) : key(key), next(nullptr), previous(nullptr) {}
Node::~Node() {
//    delete[] next;
//    delete[] previous;
}
