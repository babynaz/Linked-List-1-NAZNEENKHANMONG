#ifndef DOUBLY_H
#define DOUBLY_H

#include "node.h"

class DoublyLL {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertBetween(Node* newNode, Node* prev, Node* next);

public:
    ~DoublyLL();
    bool isEmpty();
    void insert(int);
    void remove(int);
    void print();
    void printRev();
};

bool DoublyLL::isEmpty() {
    return this->head == nullptr;
}

void DoublyLL::insertBetween(Node* newNode, Node* prev, Node* next) {
    newNode->setPrev(prev);
    newNode->setNext(next);
    if (prev != nullptr)
        prev->setNext(newNode);
    if (next != nullptr)
        next->setPrev(newNode);
}

void DoublyLL::insert(int value) {
    Node* newNode = new Node(value);

    // Empty
    if (this->isEmpty()) {
        this->head = this->tail = newNode;
        return;
    }

    // Insert at head
    if (value < this->head->getData()) {
        this->head->setPrev(newNode);
        newNode->setNext(this->head);
        this->head = newNode;
    }

    // Insert at tail
    else if (value > this->tail->getData()) {
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail = newNode;
    }

    // Other Cases
    else {
        Node* temp;
        for (temp = this->head; temp->getNext() != nullptr && temp->getData() < value; temp = temp->getNext())
            ;
        Node* tempPrev = temp->getPrev();
        this->insertBetween(newNode, tempPrev, temp);
    }
}

void DoublyLL::remove(int value) {
    // Find node
    Node* temp;
    for (temp = this->head; temp != nullptr && temp->getData() != value; temp = temp->getNext())
        ;

    // Not found
    if (temp == nullptr)
        return;

    if (temp != this->tail)
        temp->getNext()->setPrev(temp == this->head ? nullptr : temp->getPrev());
    // Found at tail
    else
        this->tail = this->tail->getPrev();

    if (temp != this->head)
        temp->getPrev()->setNext(temp == this->tail ? nullptr : temp->getNext());
    // Found at head
    else
        this->head = this->head->getNext();

    delete temp;
}

void DoublyLL::print() {
    for (Node* temp = this->head; temp != nullptr; temp = temp->getNext())
        std::cout << temp->getData() << " <--> ";
    std::cout << "X" << std::endl;
}

void DoublyLL::printRev() {
    for (Node* temp = this->tail; temp != nullptr; temp = temp->getPrev())
        std::cout << temp->getData() << " <--> ";
    std::cout << "X" << std::endl;
}

DoublyLL::~DoublyLL() {
    for (Node* temp = this->head; this->head != nullptr; temp = this->head) {
        this->head = this->head->getNext();
        delete temp;
    }
}

#endif
