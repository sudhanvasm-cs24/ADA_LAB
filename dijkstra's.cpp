#include <bits/stdc++.h>

#define MAX 10

using namespace std;

void dijkstra (int n, vector <vector<int>> &cost, int src) {
    int u = -1;
    vector <int> dis (MAX, INT_MAX);
    vector <bool> vis (MAX, false);
    dis[src] = 0;
    for (int i = 0; i < n; i++) {
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && dis[j] < mini) {
                mini = dis[j];
                u = j;
            }
        }
        vis[u] = true;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && cost[u][j] != 0 && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }
    cout << "Shortest Path" << endl;
    for (int i = 0; i < n; i++) {
        cout << src << " -> " << i << " = " << dis[i] << endl;
    }
}

int main () {
    int src, n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector <vector<int>> cost(n, vector<int> (n));
    cout << "Enter the cost adjacency matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra (n, cost, src);
    return 0;
}