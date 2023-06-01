#include <iostream>
using namespace std;

struct Node { // ��������� ���� ������
    int data;
    bool isBlack;
    Node* left;
    Node* right;
    Node* parent;
};

Node* newNode(int data, Node* parent) { // ������� ��� �������� ������ ����
    Node* node = new Node();
    node->data = data;
    node->isBlack = false;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

Node* insert(Node* root, int data) { // ������� ��� ������� ������ ���� � ������
    if (root == NULL) {
        return newNode(data, NULL);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
        root->left->parent = root;
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }
    return root;
}

Node* deleteNode(Node* root, int data) { // ������� ��� �������� ���� �� ������
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // ��������� ���� ����� �� ����� ������ �������
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp != NULL) {
                temp->parent = root->parent;
            }
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp != NULL) {
                temp->parent = root->parent;
            }
            delete root;
            return temp;
        }

        // ��������� ���� ����� ���� ��������
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(Node* root) { // ������� ��� ������������� ������ ������
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int sumLeaves(Node* root) { // ������� ��� �������� ����� �������
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
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the data for each node: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }
    cout << "In-order traversal of the tree: ";
    inOrder(root);
    cout << endl;
    int sum = sumLeaves(root);
    cout << "Sum of leaves: " << sum << endl;
    int del;
    cout << "Enter the node to delete: ";
    cin >> del;
    root = deleteNode(root, del);
    cout << "In-order traversal of the tree after deletion: ";
    inOrder(root);
    cout << endl;
    int ins;
    cout << "Enter the node to insert: ";
    cin >> ins;
    root = insert(root, ins);
    cout << "In-order traversal of the tree after insertion: ";
    inOrder(root);
    cout << endl;
}