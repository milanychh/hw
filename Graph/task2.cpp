#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> Gr(n + 1); // ������� ������ ���������

    cout << "Enter edges: " << endl; // ��������� ������ ���������
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y);
        Gr[y].push_back(x); // ��� ������������������ ����� ��������� ��� ��������������
    }

    for (int i = 1; i <= n; i++) {
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end()); // ������� ���������
    }
    // ������� ���������� ������� ������ ��� ������ �������
    for (int x = 0; x < n; x++) {
        int count = Gr[x].size();
        cout << "Vertex " << x << ": " << count << " adjacent vertices" << endl;
    }

    // ��������� �����
    int a, b;
    cout << "Enter vertices A and B to add an edge: ";
    cin >> a >> b;
    Gr[a].push_back(b);
    Gr[b].push_back(a);

    // ������� ���������� ������� ������ ��� ������ �������
    for (int x = 0; x < n; x++) {
        int count = Gr[x].size();
        cout << "Vertex " << x << ": " << count << " adjacent vertices" << endl;
    }
}