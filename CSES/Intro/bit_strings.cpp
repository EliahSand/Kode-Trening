#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, s = 1;
    cin >> n;

    for(int i = 0; i < n ; i++){
        s = 2*s%((int)1e9 +7 );
    }
    
    cout << s;

    return 0;
}