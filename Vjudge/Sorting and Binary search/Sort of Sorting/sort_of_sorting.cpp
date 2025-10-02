#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool nameChecker(string name1, string name2) {
    // Check lengths and handle edge cases
    if (name1.empty() || name2.empty()) return false;

    char firstLetter1 = name1[0];
    char secondLetter1 = (name1.length() > 1) ? name1[1] : '\0'; // Use '\0' if no second character

    char firstLetter2 = name2[0];
    char secondLetter2 = (name2.length() > 1) ? name2[1] : '\0';

    // Compare first letters
    if (firstLetter1 < firstLetter2) {
        return true;
    } else if (firstLetter1 > firstLetter2) {
        return false;
    }

    // If first letters are equal, compare second letters
    return secondLetter1 < secondLetter2;
}

vector<string> insertionSort(vector<string> nameList, int length){
    for(int i = 1; i < length; i++){
        string name = nameList[i];
        int j = i - 1;
        
        while (j>=0 && nameChecker(name, nameList[j])){
            nameList[j + 1] = nameList[j];
            j -= 1;
        }
        nameList[j+1] = name;

    }
    return nameList;
}

void printArray(vector<string> arr){
    for(auto i : arr){
        cout << i << endl;
    }
}


int main(){

    int n;
    cin >> n;
    while (n!=0){

        vector<string> listOfNames;
        for(int i = 0; i < n; i++){
            string name;
            cin >> name;
            listOfNames.push_back(name);
        }

        printArray(insertionSort(listOfNames, listOfNames.size()));
        cout << endl;
        cin >> n;
    }

    return 0;
}