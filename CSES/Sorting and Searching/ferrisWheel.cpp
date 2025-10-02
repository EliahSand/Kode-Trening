#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll solve(vector<ll> arr, ll N, ll X){
    sort(arr.begin(), arr.end());

    ll light = 0, heavy = N-1;
    ll ans = 0;
    
    while(heavy>=light){
        if(arr[light] + arr[heavy] <= X){
            ans++;
            light++;
            heavy--;
        }
        else {
            ans++;
            heavy--;
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll nrOfChildren,maxWeight,child;
    vector<ll>children;
    cin >> nrOfChildren >> maxWeight;
    for(int i = 0; i < nrOfChildren; i++){
        cin >> child;
        children.push_back(child);
    }

    cout << solve(children, nrOfChildren, maxWeight) << endl;
    return 0;
}
