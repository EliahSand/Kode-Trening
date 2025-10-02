#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
typedef long long ll;
using namespace std;


int main(){

    const int mxN = 2e5;

    array <int,2> a[mxN];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> times;
    for(int i = 0; i < n ; i++){
        int start, end;
        cin >> a[i][1] >> a[i][0];
    }

    /*
    a[end][start]
    */
    
    sort(a,a+n);

    int current = 0;
    int maxMovies = 0;

    for(int i = 0; i < n ; i++){
        if(a[i][1] >= current){
            maxMovies++;
            current = a[i][0];
        }
    }

    cout << maxMovies << endl;


    return 0;
}