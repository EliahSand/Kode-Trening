#include <iostream>
#include <set>
#include <ios>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x;
    cin >> n;
    set<ll> distinct;
    for(int i = 0; i < n; i++){
        cin >> x;
        distinct.insert(x);
    }

    cout << distinct.size() << endl;

    return 0;
}

/*
time complexity:
for loop for all values -> O(n)

spatial compx:
worst case, all different -> O(n)*/