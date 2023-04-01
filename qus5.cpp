#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Perform DFS from city 1
    dfs(1);

    // Check if city n is reachable from city 1
    if (vis[n]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

