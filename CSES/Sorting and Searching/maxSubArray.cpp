#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll maxSubArray(ll A[], ll izq, ll der) {
    if (der - izq + 1 == 1) {  // Base case: single element
        return A[izq];
    } else {
        /* Divide */
        ll m = (izq + der) / 2;

        /* Conquer */
        ll s1 = maxSubArray(A, izq, m);       // Max sum in left subarray
        ll s2 = maxSubArray(A, m + 1, der);  // Max sum in right subarray

        /* Combine */
        ll s = A[m];
        ll M1 = A[m];

        // Max sum in the left part including midpoll
        for (ll j = m - 1; j >= izq; j--) {
            s += A[j];
            if (s > M1) {
                M1 = s;
            }
        }

        // Max sum in the right part including m + 1
        s = 0;  // Reset sum
        ll M2 = 0;  // Default to 0 for empty right part
        if (m + 1 <= der) {  // Check if right part exists
            s = A[m + 1];
            M2 = A[m + 1];
            for (ll j = m + 2; j <= der; j++) {
                s += A[j];
                if (s > M2) {
                    M2 = s;
                }
            }
        }

        // Return the maximum of all possible subarray sums
        return max({s1, s2, M1, M2, M1 + M2});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll c,x;
    cin >> c;
    ll arr[c];
    for(ll i = 0; i < c; i++){
        cin >> arr[i];
    }  
    cout << maxSubArray(arr, 0, c-1) << endl;  // Call with indices 0 to n-1
    return 0;
}