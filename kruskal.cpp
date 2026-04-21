#include <iostream>

#define MAX 10

using namespace std;

int find (int v, int parent[]) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void union1 (int i, int j, int parent[]) {
    if (i < j) {
        parent[j] = i;
    }
    else {
        parent[i] = j;
    }
}

void kruskal (int n, int adj[][MAX]) {
    int count = 0, k = 0, sum = 0;
    int i, j, u, v;
    int parent[n];
    int mst[n - 1][2];
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }
    while (count != n - 1) {
        int min = INT_MAX;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj[i][j] < min && adj[i][j] != 0) {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        i = find (u, parent);
        j = find (v, parent);
        if (i != j) {
            union1 (i, j, parent);
            mst[k][0] = u;
            mst[k][1] = v;
            k++;
            count++;
            sum += adj[u][v];
        }
        adj[u][v] = adj[v][u] = INT_MAX;
    }
    if (count == n - 1) {
        cout << "Minimum Spanning Tree edges: ";
        for (i = 0; i < k; i++) {
            cout << mst[i][0] << mst[i][1];
            if (i != k - 1) cout << " -> ";
        }
        cout << "\nWeight: " << sum;
    }
}

int main () {
    int adj[MAX][MAX];
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    kruskal (n, adj);
    return 0;
}