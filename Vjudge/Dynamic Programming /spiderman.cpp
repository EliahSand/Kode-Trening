#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <numeric>


using namespace std;

// Constants
const int MAX_HEIGHT = 30000; // Maximum sum of all heights (similar to Python's `s`)
const int INF = INT_MAX;      // Represents unreachable states

void climb(int n, const vector<int>& d) {
    int s = accumulate(d.begin(), d.end(), 0); // Total height difference

    // Early exit: If total height is odd, it's impossible to balance
    if (s % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // DP tables
    vector<vector<int>> opt(n, vector<int>(s + 1, INF));
    vector<vector<int>> dec(n, vector<int>(s + 1, 0));

    // First move always goes up
    opt[0][d[0]] = d[0];
    dec[0][d[0]] = 1; // 1 = up, -1 = down

    // Fill DP table
    for (int i = 1; i < n; ++i) {
        for (int h = 0; h <= s; ++h) {
            if (opt[i - 1][h] != INF) {
                // Move down
                if (h >= d[i] && opt[i][h - d[i]] > opt[i - 1][h]) {
                    opt[i][h - d[i]] = opt[i - 1][h];
                    dec[i][h - d[i]] = -1;
                }

                // Move up
                int temp_opt = max(opt[i - 1][h], h + d[i]);
                if (opt[i][h + d[i]] > temp_opt) {
                    opt[i][h + d[i]] = temp_opt;
                    dec[i][h + d[i]] = 1;
                }
            }
        }
    }

    // Check if reaching height 0 is possible
    if (opt[n - 1][0] == INF) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Reconstruct the solution
    string solution(n, ' ');
    int h = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dec[i][h] == 1) {
            solution[i] = 'U';
            h -= d[i];
        } else {
            solution[i] = 'D';
            h += d[i];
        }
    }

    cout << solution << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        climb(n, d);
    }

    return 0;
}