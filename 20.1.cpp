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

void decimalToBinary(int n, Node*& top) {
    Node* binaryStack = NULL;
    while (n > 0) {
        int rem = n % 2;
        push(binaryStack, rem);
        n /= 2;
    }
     while (binaryStack != NULL) {
        push(top, pop(binaryStack));
    }
}

int main() {
    Node* top = NULL;
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter integer #" << i + 1 << ": ";
        cin >> num;
        decimalToBinary(num, top);
    }
    printStack(top);
    return 0;
}
