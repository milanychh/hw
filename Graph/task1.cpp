#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> Gr(n + 1); // создаем список смежности

    cout << "Enter edges: " << endl; // заполняем список смежности
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y);
        Gr[y].push_back(x); // для неориентированного графа добавляем обе направленности
    }

    for (int i = 1; i <= n; i++) {
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end()); // удаляем дубликаты
    }

    // выводим количество смежных вершин для каждой вершины
    for (int x = 0; x < n; x++) {
        int count = Gr[x].size();
        cout << "Vertex " << x << ": " << count << " adjacent vertices" << endl;
    }    
}