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

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        this->root = nullptr;
    }
    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    }
                    else {
                        current = current->left;
                    }
                }
                else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }
    }
    int countNodes(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
    }
    void deleteMinNodes(Node* node, int& count) {
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr && node->right != nullptr) {
            deleteMinNodes(node->left, count);
            deleteMinNodes(node->right, count);
        }
        else if (node->left != nullptr) {
            Node* temp = node->left;
            node->data = temp->data;
            node->left = temp->left;
            node->right = temp->right;
            delete temp;
            count++;
            deleteMinNodes(node, count);
        }
        else if (node->right != nullptr) {
            Node* temp = node->right;
            node->data = temp->data;
            node->left = temp->left;
            node->right = temp->right;
            delete temp;
            count++;
            deleteMinNodes(node, count);
        }
    }
};

void printInorder(Node* root, int indent = 0) {
    if (root == nullptr) return;

    printInorder(root->right, indent + 1);

    for (int i = 0; i < indent; i++) cout << '\t';
    cout << root->data << '\n';
    printInorder(root->left, indent + 1);
}


int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);

    cout << "Original tree: ";
    cout << '\n';
    printInorder(tree.root);
    cout << endl;

    int count = 0;
    tree.deleteMinNodes(tree.root, count);

    cout << "Binary tree with minimal number of nodes: ";
    cout << '\n';
    printInorder(tree.root);
    cout << endl;

    cout << "Number of nodes removed: " << count << endl;

    return 0;
}
