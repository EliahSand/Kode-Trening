#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,h,t;
    cin >> n >> m;
    vector<ll> customers;
    multiset<ll> tickets;
    for(int i = 0; i < n; i++){
        cin >> h;
        tickets.insert(h);
    }

    for(int i = 0; i < m; i++){
        cin >> t;
        customers.push_back(t);
    }

    for(auto& cust : customers){
        auto it = tickets.upper_bound(cust);
        if(it == tickets.begin()){
            cout << -1 << endl;
        } else{
            --it;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;
}