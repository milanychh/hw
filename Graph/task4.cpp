#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> Gr(n + 1); // ������ ���������

    cout << "Enter edges: " << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y); 
        Gr[y].push_back(x);
    }

    vector<bool> visited(n + 1, false); // ������, ���������� ���������� � ���������� ��������
    queue<int> Q; // ������� ��� ������ ����� � ������
    Q.push(1); // �������� ����� � ������� 1
    visited[1] = true; 
    while (!Q.empty()) {
        int x = Q.front(); // ���� ������ ������� �� �������
        Q.pop();
        for (int y : Gr[x]) { 
            if (!visited[y]) { 
                visited[y] = true; 
                Q.push(y); 
            }
        }
    }

    bool connected = true; 
    for (int x = 1; x <= n; x++) {
        if (!visited[x]) { // ���� ������� �� ���� ��������
            connected = false; // ���� �� �������
            break;
        }
    }

    if (connected) {
        cout << "The graph is connected." << endl;
    } 
    else {
        cout << "The graph is not connected." << endl;
    }

    cout << "Adjacency list: " << endl;
    for (int x = 1; x <= n; x++) { 
        cout << x << ": ";
        for (int y : Gr[x]) {
            cout << y << " ";
        }
        cout << endl;
    }
}