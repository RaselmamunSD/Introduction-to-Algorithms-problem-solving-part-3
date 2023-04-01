#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adjList[MAXN];
bool visited[MAXN];

bool dfs(int v, int parent) {
    visited[v] = true;
    for (auto u : adjList[v]) {
        if (!visited[u]) {
            if (dfs(u, v)) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Run DFS from each unvisited node to detect cycles
    bool cycleExists = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycleExists = true;
                break;
            }
        }
    }

    if (cycleExists) {
        cout << "Cycle Exist" << endl;
    } else {
        cout << "No Cycle" << endl;
    }

    return 0;
}

