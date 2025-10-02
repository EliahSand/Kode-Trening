#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n,realSum, t, sum;

    cin >> n;
    realSum = (n*(n+1))/2;
    

    sum = 0;
    for(int i = 0; i < n-1; i++){
        cin >> t;
        sum += t;
    }
    
    cout << realSum - sum << endl;

    return 0;
}