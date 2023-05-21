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

void PreorderTraversal(tree* p) { // ������� ��� ������� ������ ������
    if (p) {
        cout << p->inf << " ";  
        PreorderTraversal(p->left);  
        PreorderTraversal(p->right);  
    }
}

int SumLeaves(tree* p, int sum = 0) { // ������� ��� ���������� ����� �������� ������� ������
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            sum += p->inf;  // ���� ���� �������� ������, ��������� ��� �������� � �����
        }
        sum = SumLeaves(p->left, sum);  // ������� ����� ���������
        sum = SumLeaves(p->right, sum);  // ������� ������ ���������
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
