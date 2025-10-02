#include <iostream>
#include <string>

using namespace std;


int solve (string S){
    int ans = 1, count = 1;
    for(int i = 1; i < S.length(); i++){
        if(S[i-1] == S[i]){
            count ++;
        }
        else {
            count = 1;
        }
        ans = max (ans, count);
    }

    return ans;
}

int main(){

    string n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}