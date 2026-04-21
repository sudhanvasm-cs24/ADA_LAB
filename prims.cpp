#include <iostream>

#define MAX 10

using namespace std;

void prim (int n, int adj[MAX][MAX]) {
    int u, v, k = 0, sum = 0;
    int visited[10];
    int mst[10][10];
    for (int i = 0; i < n; i++) 
        visited[i] = 0;
    visited[0] = 1;
    while (k < n - 1) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] == 0 && adj[i][j] < min && adj[i][j] != 0) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        mst[k][0] = u;
        mst[k][1] = v;
        k++;
        sum += min;
        visited[v] = 1;
    }
    cout << "Minimum Spanning Tree edges: ";
    for (int i = 0; i < k; i++) {
        cout << mst[i][0] << " " << mst[i][1] << " ";
    }
    cout << "\nWeight: " << sum;
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
    prim (n, adj);
    return 0;
}