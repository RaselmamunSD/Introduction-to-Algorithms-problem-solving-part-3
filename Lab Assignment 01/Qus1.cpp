#include <iostream>
#include <vector>
using namespace std;

void printAdjacencyList(vector<vector<int>>& adjList) {
    for(int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<vector<int>> adjList(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    printAdjacencyList(adjList);
    return 0;
}


