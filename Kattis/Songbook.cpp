#include <iostream>
#include <vector>
using namespace std;

int main(){

    int minutesAviable, songs;
    cin >> minutesAviable >> songs;

    vector<int> A;
    for(int i = 0; i < songs; i++){
        int song;
        cin >> song;
        A.push_back(song);
    }

    int totalSeconds = 0;
    for(int el:A){
        if(totalSeconds + el <= minutesAviable*60){
            totalSeconds+=el;
        }
    }

    cout << totalSeconds << endl;

    return 0;
}