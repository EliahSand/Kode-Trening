#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <math.h>
using namespace std;
typedef long long ll;

const int mxN = 2e5;

int main (){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, table[mxN];
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> table[i];
    }

    sort(table, table + n);

    ll med = table[n/2];
    ll counter = 0;
    for(int i = 0; i < n; i++){
        counter += abs(table[i] - med);
    }

    cout << counter << endl;

    return 0;
}
