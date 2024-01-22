#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL && rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        Node* temp = front;
        if (front == NULL) return;
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
        delete(temp);
    }
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void rearrange() {
        Node* temp = front;
        Queue positiveQueue, negativeQueue;
        while (temp != NULL) {
            if (temp->data >= 0) {
                positiveQueue.enqueue(temp->data);
            }
            else {
                negativeQueue.enqueue(temp->data);
            }
            temp = temp->next;
        }
        positiveQueue.display();
        negativeQueue.display();
        while (positiveQueue.front != NULL) {
            enqueue(positiveQueue.front->data);
            positiveQueue.dequeue();
        }
        while (negativeQueue.front != NULL) {
            enqueue(negativeQueue.front->data);
            negativeQueue.dequeue();
        }
    }
};

int main() {
    Queue q;
    ifstream inFile("C://Users//zarin//input.txt");
    int x;
    while (inFile >> x) {
        q.enqueue(x);
    }
    inFile.close();
    cout << "Original queue: ";
    q.display();
    cout << "Rearranged queue: ";
    q.rearrange();
    return 0;
}
