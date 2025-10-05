#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int cases;

    cin >> cases;

    for (int i = 0; i < cases ; i++){
        long long pole_length, ants_on_pole;
        cin >> pole_length >> ants_on_pole;
        vector<long long> positions;
        int position;
        for(int j = 0; j < ants_on_pole; j++){
            cin >> position;
            positions.push_back(position);
        }
        sort(positions.begin(), positions.end());
        long long maxTime = 0;
        long long minTime = 0;
        // dont have the proper compiler for this
        /*for(long long antPosition : positions){
            minTime = max(minTime, min(antPosition, pole_length - antPosition));
            maxTime = max(maxTime, max (antPosition, pole_length - antPosition));
        }*/

        for(int k = 0; k < positions.size(); k++){
            long long antPosition = positions[k];
            minTime = max(minTime, min(antPosition, pole_length - antPosition));
            maxTime = max(maxTime, max (antPosition, pole_length - antPosition));
        }

        cout << minTime << " " << maxTime << endl;
    }

    return 0;
}