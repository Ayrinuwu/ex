#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    int size;
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }
    bool isEmpty() {
        return (front == nullptr);
    }
    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
};

int main() {
    Queue queue;
    string word;
    ifstream file("C://Users//zarin//input.txt");
    while (file >> word) {
        bool found = false;
        Node* current = queue.front;
        while (current != nullptr) {
            if (current->data == word) {
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            queue.enqueue(word);
        }
    }
    file.close();

    cout << "Queue contents:" << endl;
    Node* current = queue.front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Queue size: " << queue.size << endl;

    return 0;
}
