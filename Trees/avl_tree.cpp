#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int balanceFactor(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = balanceFactor(root);
    if (balance > 1 && data < root->left->data) {
        return rotateRight(root);
    }
    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && data > root->right->data) {
        return rotateLeft(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;
    printTree(root->left, space);
}

int sumLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    return sumLeaves(root->left) + sumLeaves(root->right);
}

int main() {
    Node* root = NULL;
    int n, data;
    cout << "Enter the number of nodes in AVL tree: ";
    cin >> n;
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }
    cout << "AVL tree:" << endl;
    printTree(root, 0);
    int sum = sumLeaves(root);
    cout << "Sum of leaves: " << sum << endl;
}