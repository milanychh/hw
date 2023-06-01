#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

//структура для хранения ребра графа
struct Edge {
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

//функция для добавления ребра в граф
void addEdge(vector<vector<Edge>> &Gr, int u, int v, int weight) {
    Gr[u].push_back(Edge(v, weight));
    Gr[v].push_back(Edge(u, weight));
}

//функция для нахождения кратчайшего пути от заданной вершины до всех остальных вершин
void dijkstra(vector<vector<Edge>> &Gr, int start, vector<int> &distance, vector<int> &prev) {
    int n = Gr.size();
    distance.assign(n, INT_MAX);
    prev.assign(n, -1);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto e : Gr[u]) {
            int v = e.to;
            int w = e.weight;

            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                prev[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}

//функция для вывода пути от заданной вершины до другой вершины
vector<int> getPath(int v, const vector<int> &prev) {
    vector<int> path;
    for (; v != -1; v = prev[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

//функция для вывода кратчайшего пути от заданной вершины до всех остальных вершин
void printShortestPaths(vector<vector<Edge>> &Gr, int start) {
    vector<int> distance, prev;
    dijkstra(Gr, start, distance, prev);
    int n = Gr.size();

    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "No path from " << start << " to " << i << endl;
        } else {
            cout << "Shortest path from " << start << " to " << i << ": " << distance[i] << endl;
            vector<int> path = getPath(i, prev);
            cout << "Path: ";
            for (auto v : path)
                cout << v << " ";
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    //инициализируем список смежности
    vector<vector<Edge>> Gr(n);

    //добавляем ребра в граф
    cout << "Enter the edges (from to weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(Gr, u, v, weight);
    }

    //выполняем алгоритм Дейкстры для нахождения кратчайших путей
    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;
    printShortestPaths(Gr, start);
}
