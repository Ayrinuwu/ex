#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    
public:
    Node* front;
    Node* rear;
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue() {
        if (front == nullptr) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    int getFront() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue myQueue;
    int oldValue, newValue, num;
    ifstream inputFile("C://Users//zarin//input.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    while (inputFile >> num) {
        myQueue.enqueue(num);
    }

    inputFile.close();

    cout << "Enter the old value: ";
    cin >> oldValue;
    cout << "Enter the new value: ";
    cin >> newValue;

    int size = 0;
    Node* temp = myQueue.front;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    for (int i = 0; i < size; i++) {
        if (myQueue.getFront() == oldValue) {
            myQueue.dequeue();
            myQueue.enqueue(newValue);
        }
        else {
            myQueue.enqueue(myQueue.getFront());
            myQueue.dequeue();
        }
    }

    cout << "New queue: ";
    temp = myQueue.front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
