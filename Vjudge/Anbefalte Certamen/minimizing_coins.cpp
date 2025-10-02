#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#define INF 10000000000
typedef long long ll;
using namespace std;

ll solve (vector<ll> &arr, ll &n, ll &x){
    vector<ll> dp(x+1,INF);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] > i || dp[i - arr[j]] == INF){
                continue;
            }
            dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }

    if (dp[x] != INF){
        return dp[x];
    }

    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,x,c;
    cin >> n >> x;
    vector<ll> arr;
    for (int i = 0; i < n; i++){
        cin >> c;
        arr.push_back(c);
    }

    cout << solve(arr, n, x) << endl;

    return 0;
}