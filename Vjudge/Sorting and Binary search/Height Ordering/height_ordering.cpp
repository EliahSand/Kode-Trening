#include <iostream>
#include <vector>
typedef long long ll ;
using namespace std;

int insertionSort(vector<int>& classList, int n){
    int steps = 0;
    for (int i = 1; i < n ; i++){
        int key = classList[i];
        int j = i - 1;


        while((j>=0 && classList[j] > key)){
            classList[j+1] = classList[j];
            j = j - 1;
            steps++;
        }

        classList[j+1] = key;
    }
    return steps;
}

int main(){

    int P;
    cin >> P;
    
    for(int i = 1; i <= P; i++){
        vector<int> classList;
        int classID;
        cin >> classID;
        for(int j = 0; j < 20 ; j++){
            int num;
            cin >> num;
            classList.push_back(num);
        }

        int steps = insertionSort(classList, classList.size());

        cout << classID << " " << steps << endl;
    }

    return 0;
}