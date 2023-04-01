#include <bits/stdc++.h>
using namespace std;



int n, m;
char a[1005][1005];
bool visited[1005][1005];
int prev_move[1005][1005];

int di[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
int dj[] = {0, 1, 0, -1};

bool is_valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !visited[i][j]);
}

void bfs(pair<int, int> start_pos) {
    queue<pair<int, int>> q;
    q.push(start_pos);
    visited[start_pos.first][start_pos.second] = true;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
            cout << "YES\n";
            vector<char> path;
            while (prev_move[i][j] != -1) {
                int move = prev_move[i][j];
                if (move == 0) path.push_back('U');
                else if (move == 1) path.push_back('R');
                else if (move == 2) path.push_back('D');
                else path.push_back('L');
                int ni = i - di[move], nj = j - dj[move];
                i = ni, j = nj;
            }
            reverse(path.begin(), path.end());
            for (char c : path) cout << c;
            cout << '\n';
            return;
        };

