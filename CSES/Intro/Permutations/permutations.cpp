#include <iostream>

using namespace std;

void adjacent(long long n){
    for (int i = 2; i <= n ; i += 2){
        cout << i << " ";
    }
    
    for(int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
}

int main(){

    long long n;

    cin >> n;

    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
    } else{
        adjacent(n);
    }

    return 0;
}