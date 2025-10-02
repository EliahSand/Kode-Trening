#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void twoSets(ll n){
     ll totalSum = n*(n+1)/2;
     if(totalSum %2 != 0){
        cout << "NO" << endl;
     } else{
        cout << "YES" << endl;
        vector <ll> set1,set2;
        vector <ll> visited(1+n,0);

        ll sum_set1 = 0;
        ll max_element = n;

        while(sum_set1 < totalSum/2){
            ll remaining_sum = totalSum/2 - sum_set1;

            if(remaining_sum > max_element){
                set1.push_back(max_element);
                visited[max_element] = 1;
                sum_set1 += max_element;
                max_element--;
            } else{
                set1.push_back(remaining_sum);
                visited[remaining_sum]=1;
                sum_set1 = totalSum/2;
            }
        }

        for(int i = 1; i <= n; i++){
            if(visited[i]==0){
                set2.push_back(i);
            }
        }

        cout << set1.size() << endl;
        for(auto element : set1){
            cout << element << " ";
        }

        cout << endl;

        cout << set2.size() << endl;
        for(auto element : set2){
            cout << element << " ";
        }
     }
}

int main(){

    ll t;
    cin >> t;
    twoSets(t);

    return 0;

}