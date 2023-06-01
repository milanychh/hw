#include <iostream>
using namespace std;

struct tree {
    int inf;
    tree* left;
    tree* right;
};

tree* newNode(int inf) {
    tree* Tree = new tree();
    Tree->inf = inf;
    Tree->left = NULL;
    Tree->right = NULL;
    return Tree;
}

tree* insert(tree* root, int inf) {
    if (root == NULL) {
        return newNode(inf);
    }
    if (inf < root->inf) {
        root->left = insert(root->left, inf);
    } 
    else if (inf > root->inf) {
        root->right = insert(root->right, inf);
    }
    return root;
}

void inOrder(tree* root) { // вывод дерева симметричным обходом
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->inf << " ";
    inOrder(root->right);
}

int countOnlyLeft(tree* root) { // подсчет количества узлов с только левым потомком
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right == NULL) {
        return 1 + countOnlyLeft(root->left);
    }
    return countOnlyLeft(root->left) + countOnlyLeft(root->right);
}

int main() {
    tree* root = NULL;
    int n, inf;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inf;
        root = insert(root, inf);
    }
    inOrder(root);
    cout << endl;
    cout << "Number of nodes with only left child: " << countOnlyLeft(root) << endl;
}