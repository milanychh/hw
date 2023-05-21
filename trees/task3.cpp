#include <iostream>
using namespace std;


struct tree {
    int inf;  
    tree* left;  
    tree* right;  
};

tree* BuildTree(int n) {
    if (n == 0) {
        return NULL;
    }
    int nl = n / 2;
    int nr = n - nl - 1;

    tree* p = new tree;
    cin >> p->inf;

    p->left = BuildTree(nl);
    p->right = BuildTree(nr);
    return p;
}

void PreorderTraversal(tree* p) { // функция для прямого обхода дерева
    if (p) {
        cout << p->inf << " ";  
        PreorderTraversal(p->left);  
        PreorderTraversal(p->right);  
    }
}

int SumLeaves(tree* p, int sum = 0) { // функция для вычисления суммы значений листьев дерева
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            sum += p->inf;  // если узел является листом, добавляем его значение к сумме
        }
        sum = SumLeaves(p->left, sum);  // обходим левое поддерево
        sum = SumLeaves(p->right, sum);  // обходим правое поддерево
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    tree* root = BuildTree(n);  

    PreorderTraversal(root);  
    cout << endl;

    int sum = SumLeaves(root); 
    cout << "Sum of leaves: " << sum << endl;
}
