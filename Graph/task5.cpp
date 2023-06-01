#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> Gr(n + 1); // список смежности

    cout << "Enter edges: " << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y); 
    }

    vector<bool> is_source(n + 1, true); // ищем истоки
    for (int x = 1; x <= n; x++) {
        for (int y : Gr[x]) {
            is_source[y] = false; 
        }
    }

    cout << "Sources: ";
    for (int x = 1; x <= n; x++) {
        if (is_source[x]) {
            cout << x << " ";
        }
    }
    cout << endl;

    cout << "Adjacency list: " << endl;
    for (int x = 1; x <= n; x++) {
        cout << x << ": ";
        for (int y : Gr[x]) {
            cout << y << " ";
        }
        cout << endl;
    }
}