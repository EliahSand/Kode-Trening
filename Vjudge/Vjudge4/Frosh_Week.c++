#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numberOfTasks, numberOfIntervals;

    // Read in number of tasks and intervals
    cin >> numberOfTasks >> numberOfIntervals;

    vector<int> taskLength(numberOfTasks);
    vector<int> quietLength(numberOfIntervals);

    // Read in task lengths
    for (int i = 0; i < numberOfTasks; i++) {
        cin >> taskLength[i];
    }

    // Read in quiet intervals
    for (int i = 0; i < numberOfIntervals; i++) {
        cin >> quietLength[i];
    }

    // Sort the lists
    sort(taskLength.begin(), taskLength.end());
    sort(quietLength.begin(), quietLength.end());

    int accomplishedTasks = 0;
    int i = 0, j = 0;  // Initialize both i and j to 0

    // Match tasks to quiet intervals
    while (i < numberOfTasks && j < numberOfIntervals) {
        if (quietLength[j] >= taskLength[i]) {
            accomplishedTasks++;
            i++; // Move on to the next task
        }
        j++; // Move on to the next quiet interval
    }

    // Output result 
    cout << accomplishedTasks << endl;

    return 0;
}