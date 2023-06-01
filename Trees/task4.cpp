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

void InorderTraversal(tree* p) { // ������� ��� ������� ������ ������
    if (p) {
        cout << p->inf << " ";  
        InorderTraversal(p->left);
        InorderTraversal(p->right);  
    }
}

void PrintLevelK(tree* p, int k) { // ������� ��� ������ ����� k-��� ������
    if (p) {
        if (k == 0) { // ���� �������� ������� ������, ������� �������� ����
            cout << p->inf << " ";
        } else { // ����� ������� �������� ���� �� ���� ������� ����
            PrintLevelK(p->left, k - 1);
            PrintLevelK(p->right, k - 1);
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    tree* root = BuildTree(n);  

    InorderTraversal(root);  
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;
    cout << "Nodes at level " << k << ": ";
    PrintLevelK(root, k);
    cout << endl;
}
