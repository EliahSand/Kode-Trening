#include <iostream>
#include <string>
#include <unordered_map>
#include <ios>
#include <algorithm>
typedef long long ll;
using namespace std;

int factorial (int n ){
    int result = 1;
    for (int i = 2; i <= n; i++){
        result*=i;
    }
    return result;
}

ll numberOfCombinations(string &str){
    unordered_map<char,int> wordMap;
    for(char c : str){
        wordMap[c] ++;
    }
    ll teller = factorial(str.size());

    ll nevner = 1;
    for(const auto[letter, count] : wordMap){
        nevner *= factorial(count);
    }

    return teller / nevner;
    
}

int main (){

    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin >> n;

    cout << numberOfCombinations(n) << endl;
    sort(n.begin(), n.end());
    do{
        cout << n << endl;
    } while (next_permutation(n.begin(), n.end()));

}