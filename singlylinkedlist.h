#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H
#include <iostream>

template <typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    void deleteValue(T value);
    void display() const;
    bool isEmpty() const;
};
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}     // Constructor initializes the head to nullptr
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* nextnode = current->next;
        delete current;
        current = nextnode;
    }
}
template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {   // Check if the list is empty    "::" is used to define the method outside the class called scope resolution operator
    return head == nullptr;
}
template <typename T>
void SinglyLinkedList<T>::insertAtBeginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}
template <typename T>
void SinglyLinkedList<T>::insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
template <typename T>
void SinglyLinkedList<T>::insertAtPosition(T value, int position) {
    if (position < 0) {
        std::cerr << "Invalid position!" << std::endl;
        return;
    }
    if (position == 0) {
        insertAtBeginning(value);
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        std::cerr << "Position out of bounds!" << std::endl;
        delete newNode;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
template <typename T>
void SinglyLinkedList<T>::deleteValue(T value) {
    if (isEmpty()) {
        std::cerr << "List is empty!" << std::endl;
        return;
    }
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node<T>* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        std::cerr << "Value not found!" << std::endl;
        return;
    }
    Node<T>* temp = current->next;
    current->next = temp->next;
    delete temp;

}
template <typename T>
void SinglyLinkedList<T>::display() const {
    if (isEmpty()) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
#endif // SINGLY_LINKEDLIST_H