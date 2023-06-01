#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

    // выводим полустепени исхода
    vector<int> outDegree(n + 1); // массив полустепеней 
    for (int x = 1; x <= n; x++) {
        for (int y : Gr[x]) { // перебираем все смежные вершины
            outDegree[x]++; // увеличиваем полустепень исхода для вершины x
        }
    }

    cout << "Outdegrees: ";
    for (int x = 1; x <= n; x++) {
        cout << outDegree[x] << " ";
    }
    cout << endl;

    // выводим список смежности
    cout << "Adjacency list: " << endl;
    for (int x = 1; x <= n; x++) {
        cout << x << ": ";
        for (int y : Gr[x]) {
            cout << y << " ";
        }
        cout << endl;
    }
}