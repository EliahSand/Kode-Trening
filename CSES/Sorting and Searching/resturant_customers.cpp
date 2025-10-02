#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
typedef long long ll;
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> times;

    for(int i = 0; i < n ; i++){
        int start, end;
        cin >> start >> end;
        times.push_back({start, 1});
        times.push_back({end, -1});
    }

    sort(times.begin(), times.end());

    int currentCustomers = 0;
    int maxCustomers = 0;

    for(const pair<int,int>& t : times){
        currentCustomers+=t.second;
        maxCustomers = max(currentCustomers, maxCustomers);
    }


    cout << maxCustomers << endl;


    return 0;
}



