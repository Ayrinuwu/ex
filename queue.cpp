//Queue h
struct QueueNode {
  int value;
  QueueNode* next = nullptr;
  QueueNode* prev = nullptr;
};

class Queue {
private:
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;
    int length = 0;
public:
    ~Queue();
    int getLength() const;
    void enqueue(const int value);
    int dequeue();
    int peek() const;
    void clear();
    bool include(const int value) const;
    int count(const int value) const;
};
//queue cpp
#include "queue.h"

Queue::~Queue() {
    clear();
}

int Queue::getLength() const {
    return length;
}

void Queue::enqueue(const int value) {
    length += 1;
    if (length == 1) head = tail = new QueueNode{value};
    else {
        head = new QueueNode{value, head};
        head->next->prev = head;
    }
}

int Queue::dequeue() {
    length -= 1;
    int value = tail->value;
    QueueNode* rem = tail;
    if (length == 0) 
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete rem;
    return value;
}

int Queue::peek() const {
    return tail->value;
}

void Queue::clear() {
    while (length > 0) dequeue();
}

bool Queue::include(const int value) const {
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}
int Queue::count(const int value) const {
    int cnt = 0;
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
//other version

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data) {
		this->data=data;
		this->next = nullptr;
	}
};
class Queue {
public:
	Node* front;
	Node* rear;
	Queue (){
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
	int pop() {
		if (front == nullptr) {
			return -1;
		}
		return front->data;
	}
	
