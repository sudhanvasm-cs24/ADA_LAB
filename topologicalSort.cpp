#include <bits/stdc++.h>

using namespace std;

#define MAX 100

void topo (vector<vector<int>> &adj, int n) {
    vector<int> indeg(n, 0), topo;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indeg[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int j = 0; j < n; j++) {
            if (adj[u][j] == 1) {
                indeg[j]--;
                if (indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
    }

    if (topo.size() != n) {
        cout << "Topological ordering not possible (Graph has cycle)\n";
    }
    else {
        cout << "Topological Ordering\n";
        for (int i : topo) {
            cout << i << "\t";
        }
    }
}

int main() {
    int n, val;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter adjacency matrix elements: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            adj[i][j] = val;
        }
    }

    topo(adj, n);
}