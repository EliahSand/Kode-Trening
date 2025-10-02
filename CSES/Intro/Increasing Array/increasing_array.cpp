#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n,x,counter = 0;

    vector<long long> table;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        table.push_back(x);
    }

    for(int i = 1; i < n; i++){
        long long add = table[i] - table[i-1];
        if(add < 0){

            table[i] = table[i] + add*(-1);
            counter += add*(-1);
        }
    }

    cout << counter << endl;

    return 0;
}