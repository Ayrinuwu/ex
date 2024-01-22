//stack h
#include <iostream>
using namespace std;

struct StackNode {
  int value;
  StackNode* next = nullptr;
};

class Stack {
private:
    StackNode* head = nullptr;
    int length = 0;
public:
    ~Stack();
    int getLength() const;
    void push(int value);
    int peek() const;
    int pop();
    void clear();
    bool include(int value) const;
    int count(int value) const;
};
//stack cpp
#include "stack.h"

Stack::~Stack() {clear();};

int Stack::getLength() const {
    return length;
}

void Stack::push(const int value) {
    head = new StackNode{value, head};
    length += 1;
}

int Stack::peek() const {
    return head->value;
}

int Stack::pop() {
    if (length > 0) {
        length -= 1;
        StackNode* rem = head;
        head = head->next;
        int value = rem->value;
        delete rem;
        return value;
    }
    return 0;
}

void Stack::clear() {
    while (length > 0) pop();
}

bool Stack::include(const int value) const {
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

int Stack::count(const int value) const {
    int cnt = 0;
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
//other version

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top) {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return 0;
    }
    else {
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
}

void printStack(Node* top) {
    cout << "Stack: ";
    while (top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}
