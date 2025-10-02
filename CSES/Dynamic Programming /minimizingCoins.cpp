#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
typedef long long ll;
#define INF 10000000000
using namespace std;

ll coinSolver(vector<ll> & A, ll& n, ll& target){
    vector<ll> dp(target+1,INF);
    dp[0] = 0;
    for(int i = 1; i <= target; i++){
        for(int j = 0; j < n; j++){
            if(A[j] > i || dp[i - A[j]] == INF ){
                continue;
            }
        dp[i] = min(dp[i], dp[i - A[j]] + 1 );
        }
    }

    if(dp[target] != INF){
        return dp[target];
    }

    return -1;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,target;
    vector<ll> coins;
    cin>> n >> target;
    for(int i = 0; i < n ; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    cout << coinSolver(coins,n,target) << endl;;
    return 0;
}
