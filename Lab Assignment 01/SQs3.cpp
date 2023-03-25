#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, int node) {
    visited[node] = true;
    recStack[node] = true;
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            if(dfs(graph, visited, recStack, neighbor)) {
                return true;
            }
        }
        else if(recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(graph, visited, recStack, i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    if(hasCycle(graph)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

