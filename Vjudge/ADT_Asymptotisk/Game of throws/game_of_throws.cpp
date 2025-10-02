#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){

    int n,k;

    cin >> n >>k;
    cin.ignore();

    vector<int> result;

    string inputLine;
    getline(cin,inputLine);

    stringstream ss (inputLine);
    string word;

    while (ss>> word){
        int number;
        if(stringstream(word) >> number){
            result.push_back(number);
        } else {
            int removeNumber;
            ss >> removeNumber;
            if(removeNumber <= result.size()){
                result.resize(result.size() - removeNumber);
            } else {
                result.clear();
            }
        }
    }

    int sum = 0;
    for(auto element : result){
        sum+=element;
    }

    int finalSum = sum%n;

    if (finalSum < 0){
        finalSum+=n;
    }

    cout << finalSum << endl;

    return 0;
}