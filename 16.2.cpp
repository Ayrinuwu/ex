#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insert(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    }
    else {
        insert(root->right, data);
    }
}

void findMax(Node* root, int level, int& maxVal) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        maxVal = max(maxVal, root->data);
    }
    else if (level > 1) {
        findMax(root->left, level - 1, maxVal);
        findMax(root->right, level - 1, maxVal);
    }
}

void printMax(Node* root) {
    int height = 1;
    while (true) {
        int maxVal = INT_MIN;
        findMax(root, height, maxVal);
        if (maxVal == INT_MIN) {
            break;
        }
        cout << "Max value on level " << height << ": " << maxVal << endl;
        height++;
    }
}

void printInorder(Node* root, int indent = 0) {
    if (root == nullptr) return;

    printInorder(root->right, indent + 1);

    for (int i = 0; i < indent; i++) cout << '\t';
    cout << root->data << '\n';
    printInorder(root->left, indent + 1);
}

int main() {
    Node* root = nullptr;
    int arr[] = { 5, 3, 7, 1, 4, 6, 8 };

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insert(root, arr[i]);
    }

    cout << "Max value on each level:" << endl;
    printMax(root);

    cout << "Inorder traversal:" << endl;
    printInorder(root);

    return 0;
}

