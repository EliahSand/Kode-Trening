#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, item, k = 2;
    
    long long discount = 0;
    cin >> n;
    vector<int> prices;
    for(int i = 0; i < n; i++){
        cin >> item;
        prices.push_back(item);
    }

    sort(prices.begin(), prices.end(), greater<int>());

    while(k<n){
        discount+=prices[k];
        k+=3;
    }

    cout << discount;

    return 0;
}