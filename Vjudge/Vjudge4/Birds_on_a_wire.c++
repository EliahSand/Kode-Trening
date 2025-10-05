#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    long long l,d;
    int n, position;

    cin >> l >> d >> n;

    vector<long long> positions;

    for (int i = 0; i < n; i++){
        cin >> position;
        positions.push_back(position);
    }

    sort(positions.begin(), positions.end());
    long long numberOfBirds = 0;

    if (n==0){
        // no birds on the wire
        long long effective_length = l -12;
        if(effective_length >= 0){
            numberOfBirds = (effective_length/d) + 1;
        }
    } else {
        // birds on the wire 

        // before the first gap
        long long start_gap = positions[0] - 6;
        if (start_gap >= d){
            numberOfBirds += start_gap / d;
        }

        for ( int i = 1; i < n; i++){
            long long gap = positions[i] - positions[i-1];
            if(gap > d){
                numberOfBirds += (gap - d)/d;
            }
        }

        //after the last bird
        long long end_gap  = (l - 6 ) - positions[n-1];
        if( end_gap >= d){
            numberOfBirds += end_gap/d;
        }

    }

    cout << numberOfBirds << endl;

    return 0;
}