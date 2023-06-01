#include <iostream>
#include <vector>
#include <queue>

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
        Gr[y].push_back(x);
    }

    vector<bool> visited(n + 1, false); // массив, содержащий информацию о посещенных вершинах
    queue<int> Q; // очередь для обхода графа в ширину
    Q.push(1); // начинаем обход с вершины 1
    visited[1] = true; 
    while (!Q.empty()) {
        int x = Q.front(); // берём первую вершину из очереди
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
        if (!visited[x]) { // если вершина не была посещена
            connected = false; // граф не связный
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