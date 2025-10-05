#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int main(){

    string line;
    int C,n;

    while (getline(cin, line)){
        stringstream ss(line);

        ss >> C >> n;
        vector<pair<int, int>> items;

        items.reserve(n);

        for(int i = 0; i < n; i++){
            getline(cin, line);
            stringstream items_stream (line);
            int value, weight;
            items_stream >> value >> weight;
            items.push_back({value, weight});
        }



    }

    return 0;
}