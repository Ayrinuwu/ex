#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, char data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

int countDigits(Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int count = 0;
        if (isdigit(root->data)) {
            count++;
        }
        count += countDigits(root->left);
        count += countDigits(root->right);
        return count;
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter characters (one per line), end -:" << endl;
    char c='0';
    cin >> c;
    while (c!='-') {
        root = insert(root, c);
        cin >> c;
    }

    cout << "Characters in order:" << endl;
    printInOrder(root);
    cout << endl;

    int digitCount = countDigits(root);
    cout << "Number of digits: " << digitCount << endl;

    return 0;
}
