#include <iostream>
#include <unordered_map>
#include <vector>
#include <ios>

typedef long long ll;
using namespace std;

vector <int> twoSum(vector<int> &A, int target){
    unordered_map<int,int> seen;
    vector<int> result;
    for(int i = 0; i < A.size(); i++){
        int compliment = target - A[i];
        if(seen.find(compliment) != seen.end()){
            result.push_back(A[compliment]);
            result.push_back(i+1);
        }
        seen.insert({compliment,i});
    }

    return result;
}