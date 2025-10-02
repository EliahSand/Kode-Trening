#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Constants
const int MAX_MENU_ITEMS = 100;
const int MAX_SUM = 30000;

// DP arrays
int dp[MAX_SUM + 1];       // Stores the number of ways to make each sum
int backtrack[MAX_SUM + 1]; // Tracks the last item used to reach each sum

int main() {
    int n, m; // Number of menu items and orders
    cin >> n;

    vector<int> menu(n);
    for (int i = 0; i < n; ++i) {
        cin >> menu[i];
    }

    cin >> m;
    vector<int> orders(m);
    for (int i = 0; i < m; ++i) {
        cin >> orders[i];
    }

    for (int orderSum : orders) {
        // Reset DP arrays
        memset(dp, 0, sizeof(dp));
        memset(backtrack, -1, sizeof(backtrack));

        dp[0] = 1; // There's one way to achieve sum 0 (use no items)

        // Iterative DP to calculate the number of ways to achieve each sum
        for (int i = 0; i < n; ++i) {
            for (int s = menu[i]; s <= orderSum; ++s) {
                if (dp[s - menu[i]] > 0) {
                    dp[s] += dp[s - menu[i]];

                    // Cap dp[s] at 2 to detect ambiguity
                    if (dp[s] > 2) dp[s] = 2;

                    // Track the last item used to reach sum `s`
                    if (dp[s - menu[i]] == 1 && dp[s] == 1) {
                        backtrack[s] = i;
                    }
                }
            }
        }

        // Determine the result for the current order sum
        if (dp[orderSum] == 0) {
            cout << "Impossible\n";
        } else if (dp[orderSum] > 1) {
            cout << "Ambiguous\n";
        } else {
            // Unique solution - reconstruct it
            vector<int> solution;
            int currentSum = orderSum;
            while (currentSum > 0 && backtrack[currentSum] != -1) {
                int itemIndex = backtrack[currentSum];
                solution.push_back(itemIndex + 1); // Store 1-based index
                currentSum -= menu[itemIndex];
            }
            reverse(solution.begin(), solution.end()); // Reverse to get correct order
            for (int item : solution) {
                cout << item << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}