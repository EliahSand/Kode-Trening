#include <iostream>
typedef long long ll;
using namespace std;


int main(){

    ll n;
    cin >> n;

    ll res = 0;
    for(int i = 5; i <= n; i *= 5){
        res += n/i;
    }

    cout << res << endl;

    return 0;
}