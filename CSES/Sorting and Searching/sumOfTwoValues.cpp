#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;

bool solve(vector<ll> &arr, ll &targ){
    unordered_map<ll,ll> seen;
    bool flag = true;
    for(int i = 0; i < arr.size();i++){
        ll complement = targ - arr[i];
        if(seen.find(complement) != seen.end()){
            cout << seen[complement] << " " << i + 1 <<  endl;
            return true;
        }
        seen.insert({ arr[i], i + 1});
    }
    return false;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll arrSize,targ,x;
    cin >> arrSize >>targ;
    vector<ll> arr;
    for(int i = 0; i < arrSize; i++){
        cin >> x;
        arr.push_back(x);
    } 
    
    if(!solve(arr, targ)){
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}