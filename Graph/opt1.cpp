#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool hasEulerianPath(vector<vector<int>>& Gr) {
    int n = Gr.size();
    int odd_degree_count = 0;
    for (int i = 0; i < n; i++) {
        int degree = Gr[i].size();
        if (degree % 2 != 0) {
            odd_degree_count++;
        }
    }
    if (odd_degree_count == 0 || odd_degree_count == 2) {
        return true;
    } else {
        return false;
    }
}

void dfsEulerianPath(vector<vector<int>>& Gr, vector<bool>& visited, stack<int>& path, int u) {
    visited[u] = true;
    for (int v : Gr[u]) {
        if (!visited[v]) {
            path.push(v);
            dfsEulerianPath(Gr, visited, path, v);
            path.pop();
        }
    }
}

void findEulerianPath(vector<vector<int>>& Gr) {
    int n = Gr.size();
    vector<bool> visited(n, false);
    stack<int> path;
    int start = 0;
    while (Gr[start].empty()) {
        start++;
    }
    path.push(start);
    dfsEulerianPath(Gr, visited, path, start);
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}

void findEulerianCycle(vector<vector<int>>& Gr) {
    int n = Gr.size();
    vector<bool> visited(n, false);
    stack<int> path;
    int start = 0;
    while (Gr[start].empty()) {
        start++;
    }
    path.push(start);
    dfsEulerianPath(Gr, visited, path, start);
    while (!path.empty()) {
        int u = path.top();
        path.pop();
        if (!path.empty()) {
            int v = path.top();
            if (Gr[u].size() == 1 && Gr[v].size() == 1) {
                cout << u << " ";
            } else {
                cout << u << " -> ";
            }
        } else {
            cout << u;
        }
    }
}

void dfsTopologicalSort(vector<vector<int>>& Gr, vector<bool>& visited, vector<int>& topo_order, int u, int& time) {
    visited[u] = true;
    time++;
    for (int v : Gr[u]) {
        if (!visited[v]) {
            dfsTopologicalSort(Gr, visited, topo_order, v, time);
        }
    }
    time++;
    topo_order[u] = time;
}

void topologicalSort(vector<vector<int>>& Gr) {
    int n = Gr.size();
    vector<bool> visited(n, false);
    vector<int> topo_order(n, 0);
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsTopologicalSort(Gr, visited, topo_order, i, time);
        }
    }
    vector<pair<int, int>> order_pairs(n);
    for (int i = 0; i < n; i++) {
        order_pairs[i] = make_pair(topo_order[i], i);
    }
    sort(order_pairs.rbegin(), order_pairs.rend());
    for (int i = 0; i < n; i++) {
        cout << order_pairs[i].second << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Gr[u].push_back(v);
        Gr[v].push_back(u);
    }
    cout << "Adjacency list:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : Gr[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    if (hasEulerianPath(Gr)) {
        cout << "Eulerian path or cycle: ";
        findEulerianCycle(Gr);
        cout << endl;
    } 
    else {
        cout << "No Eulerian path or cycle." << endl;
    }
    cout << "Topological sort: ";
    topologicalSort(Gr);
} 