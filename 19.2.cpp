#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void buildBalancedTree(Node*& root, int arr[], int start, int end) {
    if (start > end) return;
    int mid = (start + end) / 2;
    root = new Node;
    root->data = arr[mid];
    root->left = NULL;
    root->right = NULL;
    buildBalancedTree(root->left, arr, start, mid - 1);
    buildBalancedTree(root->right, arr, mid + 1, end);
}

void splitTree(Node* root, int negArr[], int posArr[], int& negCount, int& posCount) {
    if (root == NULL) return;
    splitTree(root->left, negArr, posArr, negCount, posCount);
    if (root->data < 0) {
        negArr[negCount++] = root->data;
    }
    else {
        posArr[posCount++] = root->data;
    }
    splitTree(root->right, negArr, posArr, negCount, posCount);
}

void printTree(Node* root,int indent=0) {
    cout << '\n';
    if (root == nullptr) return;

    printTree(root->right, indent + 1);

    for (int i = 0; i < indent; i++) cout << '\t';
    cout << root->data << '\n';
    printTree(root->left, indent + 1);
}
void insert(Node*& root, int data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data) {
        insert(root->left, data);
    }
    else {
        insert(root->right, data);
    }
}

void buildTree(Node*& root) {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter node #" << i + 1 << ": ";
        cin >> data;
        insert(root, data);
    }
}

int main() {
    Node* root = NULL;
    buildTree(root);
    int negArr[100], posArr[100];
    int negCount = 0, posCount = 0;
    splitTree(root, negArr, posArr, negCount, posCount);

    Node* negRoot = NULL;
    Node* posRoot = NULL;
    buildBalancedTree(negRoot, negArr, 0, negCount - 1);
    buildBalancedTree(posRoot, posArr, 0, posCount - 1);

    cout << "Negative tree: ";
    printTree(negRoot);
    cout << endl;

    cout << "Positive tree: ";
    printTree(posRoot);
    cout << endl;

    return 0;
}

