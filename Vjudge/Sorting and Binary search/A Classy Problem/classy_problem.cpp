#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

// Helper function to print the sorted names
void printArray(const vector<string>& arr) {
    for (const auto& name : arr) {
        cout << name << endl;
    }
}

// Function to convert class levels into numeric values
vector<int> splitConvert(const string& str, char delimiter) {
    vector<int> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        if (token == "upper") {
            tokens.push_back(3);
        } else if (token == "middle") {
            tokens.push_back(2);
        } else { // "lower"
            tokens.push_back(1);
        }
    }
    return tokens;
}

// Function to normalize two class rankings to the same length
void normalizeClasses(vector<int>& a, vector<int>& b) {
    while (a.size() < b.size()) {
        a.push_back(2); // Pad with "middle" (2)
    }
    while (b.size() < a.size()) {
        b.push_back(2); // Pad with "middle" (2)
    }
}

// Function to compare two class rankings lexicographically, with tie-breaking by name
bool compareRank(pair<string, vector<int>>& p1, pair<string, vector<int>>& p2) {
    vector<int> a = p1.second;
    vector<int> b = p2.second;

    // Normalize class lengths
    normalizeClasses(a, b);

    // Compare rankings lexicographically
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) return true;  // p1 is ranked higher
        if (a[i] < b[i]) return false; // p2 is ranked higher
    }

    // Tie-break by lexicographical name comparison
    return p1.first < p2.first;
}

int main() {
    int T, n;

    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    for (int t = 0; t < T; ++t) {
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        vector<pair<string, vector<int>>> familyTree;

        // Read input and populate familyTree
        for (int i = 0; i < n; ++i) {
            string input;
            getline(cin, input);

            size_t lastSpace = input.find_last_of(" ");
            if (lastSpace == string::npos) {
                cout << "Invalid input format: " << input << endl;
                continue;
            }

            string trimmedInput = input.substr(0, lastSpace); // Exclude the last word "class"
            size_t colonPos = trimmedInput.find(":");
            if (colonPos == string::npos) {
                cout << "Invalid input format: " << trimmedInput << endl;
                continue;
            }

            string key = trimmedInput.substr(0, colonPos); // Extract the name
            string ranking = trimmedInput.substr(colonPos + 1); // Extract the ranking

            familyTree.emplace_back(key, splitConvert(ranking, '-'));
        }

        // Sort the familyTree by rank (descending order)
        sort(familyTree.begin(), familyTree.end(), compareRank);

        // Print the sorted names
        for (const auto& entry : familyTree) {
            cout << entry.first << endl;
        }

        cout << "========================" << endl;
    }

    return 0;
}