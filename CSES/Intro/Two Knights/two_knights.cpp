#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;

void knights(ll n){
    ll totalWays = pow(n,2)*((pow(n,2)-1)/2);
    ll attackingWays = 2*(n-1)* 2*(n-2);
    cout << totalWays - attackingWays << endl;
}

int main(){

    ll t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        knights(i);
    }
    
    return 0;
}