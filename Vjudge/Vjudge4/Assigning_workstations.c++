#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    long long n,m;
    cin >> n >> m;

    //make an array of pairs 
    vector<pair<long long, long long> > researchers(n);

    //populate the array 
    for(int i = 0; i < n; i++){
        long long a,s;
        cin >> a >> s;
        researchers[i] = {a,s};
    }

    //sort researchers by arrival time 
    sort(researchers.begin(), researchers.end());

    //min-heap to keep track of the earliest time a workstation becomes free
    // "greater" makes it min-heap aka smallest item at the top 
    priority_queue<long long, vector<long long>, greater<long long> > freeTimes;
    int unlockSavings = 0;

    for( const auto&[arrival, stay] : researchers){
        long long departure = arrival + stay;

        //remove any workstations that have locked before the current researers arrival 
        while (!freeTimes.empty() && freeTimes.top() < arrival - m) {
            freeTimes.pop();
        }

        //check if the workstation can be used
        if(!freeTimes.empty() && freeTimes.top() <= arrival && freeTimes.top() + m >= arrival){
            //Reuse the workstation -> removce it from the top
            freeTimes.pop();
            //one save made -> add to the savings 
            unlockSavings++;
        }

        // push current researchers departure time into the min-heap
        freeTimes.push(departure);
    }

    cout << unlockSavings << endl;
    return 0;
}