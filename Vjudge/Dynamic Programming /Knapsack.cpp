#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to reconstruct the solution
vector<int> reconstructKnapsack(vector<vector<int>> &dp, vector<pair<int, int>> &items, int n, int W) {
    vector<int> result;
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) { // If item i was included
            result.push_back(i - 1);    // Store the item's original index
            w -= items[i - 1].second;  // Reduce the remaining capacity
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

void solveKnapsack() {
    int W, n;
    while (cin >> W >> n) {
        vector<pair<int, int>> items(n); // {value, weight}
        for (int i = 0; i < n; i++) {
            cin >> items[i].first >> items[i].second;
        }

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // Populate the DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (items[i - 1].second <= w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].second] + items[i - 1].first);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        // Reconstruct the selected items
        vector<int> selectedItems = reconstructKnapsack(dp, items, n, W);

        // Output the results
        cout << selectedItems.size() << endl;
        for (int idx : selectedItems) {
            cout << idx << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solveKnapsack();
    return 0;
}