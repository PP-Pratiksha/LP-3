#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsackTable(const vector<int>& val, const vector<int>& wt, int W) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Initialize the DP table's first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // 0 capacity, no profit
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0; // 0 items, no profit
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        int v = val[i - 1];  // Current item value
        int w = wt[i - 1];   // Current item weight
        for (int j = 1; j <= W; j++) {
            if (w <= j) {  // If the item can be included
                int incProfit = v + dp[i - 1][j - w];  // Include item
                int excProfit = dp[i - 1][j];          // Exclude item
                dp[i][j] = max(incProfit, excProfit);  // Maximize profit
            } else {
                dp[i][j] = dp[i - 1][j]; // Item can't be included
            }
        }
    }

    // Print the DP table
    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    return dp[n][W];  // Maximum profit
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapsackTable(val, wt, W);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
