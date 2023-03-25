#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int source) {
    vector<int> levels(graph.size(), -1);
    queue<int> q;
    q.push(source);
    levels[source] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int neighbor : graph[curr]) {
            if(levels[neighbor] == -1) {
                q.push(neighbor);
                levels[neighbor] = levels[curr] + 1;
            }
        }
    }
    return levels;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int edge;
            cin >> edge;
            if(edge == 1) {
                graph[i].push_back(j);
            }
        }
    }

    vector<int> levels = bfs(graph, 0);
    for(int i = 0; i < n; i++) {
        cout << "node " << i << " -> level: " << levels[i] << endl;
    }

    return 0;
}

