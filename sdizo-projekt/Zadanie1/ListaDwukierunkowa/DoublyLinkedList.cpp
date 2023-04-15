#include <iostream>
#include "DoublyLinkedList.hpp"
#include "DLLNode.hpp"
#include <fstream>
#include <random>

DoublyLinkedList::DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}
DoublyLinkedList::~DoublyLinkedList() {clear();}
void DoublyLinkedList::clear() {
    DLLNode* current = head;
    DLLNode* next = nullptr;
    
    while (current != nullptr) {
        next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::add(int key, int index) {
    DLLNode* newNode = new DLLNode(key);

    //na początek
    if (index == 0) {
        if (head == nullptr) {
            tail = newNode;
        } else {
            head->setPrevious(newNode);
            newNode->setNext(head);
        }
        head = newNode;
        size++;
        return;
    }
    
    //na koniec
    if (index >= size) {
        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->setNext(newNode);
            newNode->setPrevious(tail);
        }
        tail = newNode;
        size++;
        return;
    }
    
    DLLNode* currentNode = head;
    //na dowolne
    for (int i = 0; i < size; i++) {
        if (i == index) {
            newNode->setNext(currentNode);
            newNode->setPrevious(currentNode->getPrevious());
            currentNode->getPrevious()->setNext(newNode);
            currentNode->setPrevious(newNode);
            
            size++;
            return;
        }
        currentNode = currentNode->getNext();
    }
}

void DoublyLinkedList::deleteByValue(int val) {
    DLLNode* currentNode = head;
    
    while (currentNode != nullptr) {
        if (currentNode->getKey() == val) {
            //jeśli szukana wartość jest na początku listy
            if (currentNode->getPrevious() == nullptr) {
                head = currentNode->getNext();
                if (head != nullptr) {
                    head->setPrevious(nullptr);
                } else {
                    tail = nullptr;
                }
                //jeśli jest na końcu listy
            } else if (currentNode->getNext() == nullptr) {
                tail = currentNode->getPrevious();
                tail->setNext(nullptr);
            }
            //pozostałe
            else {
                currentNode->getPrevious()->setNext(currentNode->getNext());
                currentNode->getNext()->setPrevious(currentNode->getPrevious());
            }
            size--;
            delete currentNode;
            return;
        }
        currentNode = currentNode->getNext();
    }
}


bool DoublyLinkedList::isContainingValue(int val) {
    DLLNode* node = head;
    while (node != nullptr) {
        if (node->getKey() == val)
            return true;
        node = node->getNext();
    }
    return false;

}

void DoublyLinkedList::display() {
    DLLNode* current = head;
    
    while (current != nullptr) {
        std::cout << current->getKey() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
    
    current = tail;
    while (current != nullptr) {
        std::cout << current->getKey() << " ";
        current = current->getPrevious();
    }
    
    std::cout << std::endl;
}

void DoublyLinkedList::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    
    if (size != 0) {
        clear();
    }

    
    int newSize;
    inputFile >> newSize;
    
    
    if (inputFile.is_open()) {
        int number;
        int i = 0;
        while (inputFile >> number) {
//            std::cout << i << " : " << number << std::endl;
            add(number, i);
            i++;
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
}
void DoublyLinkedList::generateList(int size) {
    clear();
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, 100);
    
    for (int i = 0; i < size; i++) {
        add(distr(rng), i);
    }
}
