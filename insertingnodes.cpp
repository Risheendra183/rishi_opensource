#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void insertAtPosition(int position, int newData) {
        if (position == 0) {
            insertAtBeginning(newData);
            return;
        }
        Node* newNode = new Node(newData);
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "The previous node is null." << std::endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(1, 15);
    list.printList();  // Output: 10 -> 15 -> 20 -> nullptr
    return 0;
}
