#include <iostream>
#include <math.h>
#include <ios>

typedef long long ll;
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,e,m;
    cin >> a >> e >> m;
    ll real = pow(a,e);

    cout << real%m << endl;

    return 0;
}