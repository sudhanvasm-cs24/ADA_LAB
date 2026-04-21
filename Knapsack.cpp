#include <bits/stdc++.h>

using namespace std;

void knapsack(int n, int m, vector<int> &weights, vector<int> &profits) {
    vector<vector<int>> v (n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (weights[i - 1] > j) v[i][j] = v[i - 1][j];
            else 
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weights[i - 1]] + profits[i - 1]);
        }
    }

    cout << "DP Matrix\n";
    for (auto &row : v) {
        for (int i : row) {
            cout << i << "\t";
        }
        cout << endl;
    }

    vector<int> item_selected(n, 0);
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            item_selected[i - 1] = 1;
            j -= weights[i - 1];
        }
        i--;
    }

    for (int i = 0; i < n; i++) {
        if (item_selected[i]) cout << "Item " << (i + 1) << " is selected" << endl;
        else cout << "Item " << (i + 1) << " is not selected" << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weights(n), profits(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profits of item " << (i + 1) << ": ";
        cin >> weights[i] >> profits[i];
    }
    cout << "Enter knapsack capacity: ";
    cin >> m;
    knapsack(n, m, weights, profits);
    return 0;
}