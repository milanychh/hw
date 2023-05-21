#include <iostream>
using namespace std;

struct Tree {
    int inf;
    Tree* left;
    Tree* right;
};

Tree* newNode(int inf) {
    Tree* tree = new Tree();
    tree->inf = inf;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

Tree* insert(Tree* root, int inf) {
    if (root == NULL) {
        return newNode(inf);
    }
    if (inf < root->inf) {
        root->left = insert(root->left, inf);
    } else if (inf > root->inf) {
        root->right = insert(root->right, inf);
    }
    return root;
}

void inOrder(Tree* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->inf << " ";
    inOrder(root->right);
}

int height(Tree* root) { // подсчет высоты дерева
    if (root == NULL) {
        return -1; 
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } 
    else {
        return rightHeight + 1;
    }
}

int main() {
    Tree* root = NULL;
    int n, inf;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inf;
        root = insert(root, inf);
    }
    inOrder(root);
    cout << endl;
    cout << "Height of the tree: " << height(root) << endl;
}