#include <bits/stdc++.h>
using namespace std;

// Maximize sum of non-adjacent coins
// int coinRow(vector<int>& coins) {
//     int n = coins.size();
//     if (n == 0) return 0;
//     if (n == 1) return coins[0];

//     vector<int> dp(n+1, 0);
//     dp[1] = coins[0];
//     for (int i = 2; i <= n; i++) {
//         dp[i] = max(dp[i-1], dp[i-2] + coins[i-1]);
//     }
//     return dp[n];
// }

// int main() {
//     vector<int> coins = {5, 1, 2, 10};
//     cout << "Coin Row max value = " << coinRow(coins) << endl;
// }

// Minimum coins to make target
// int changeMaking(vector<int>& coins, int target) {
//     const int INF = 1e9;
//     vector<int> dp(target+1, INF);
//     dp[0] = 0;

//     for (int x = 1; x <= target; x++) {
//         for (int c : coins) {
//             if (x - c >= 0) {
//                 dp[x] = min(dp[x], dp[x-c] + 1);
//             }
//         }
//     }
//     return (dp[target] == INF ? -1 : dp[target]);
// }

// int main() {
//     vector<int> coins = {1, 3, 4};
//     int target = 6;
//     cout << "Change Making min coins = " << changeMaking(coins, target) << endl;
// }

// Max coins collected in grid path (right/down moves)
int coinCollection(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    for (int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 3, 1, 1},
        {2, 0, 0, 4},
        {1, 5, 3, 1}
    };
    cout << "Coin Collection max coins = " << coinCollection(grid) << endl;
}
