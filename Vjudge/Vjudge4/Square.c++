#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    // Store plot diameters as doubles
    vector<double> plot_diameters;
    double radius;
    for (int i = 0; i < N; i++) {
        cin >> radius;
        plot_diameters.push_back(radius * 2);  // Convert radius to diameter
    }

    // Store house effective diameters for both circular and square houses
    vector<double> house_diameters;
    for (int i = 0; i < M; i++) {
        cin >> radius;
        house_diameters.push_back(radius * 2);  // Circular house diameter
    }

    for (int i = 0; i < K; i++) {
        cin >> radius;
        // Calculate diagonal for square house (effective diameter)
        house_diameters.push_back((double)sqrt(2.0 * pow(radius, 2)));
    }

    // Sort plots and houses to process in ascending order
    sort(plot_diameters.begin(), plot_diameters.end());
    sort(house_diameters.begin(), house_diameters.end());

    int filled_plots = 0;


    for (int i = 0; i < house_diameters.size(); i++) {
        for (int j = 0; j < plot_diameters.size(); j++) {
            if (house_diameters[i] < plot_diameters[j]) {  // If house fits
                filled_plots++;
                plot_diameters[j] = -1;  // Mark plot as used
                break;
            }
        }
    }

    cout << filled_plots << endl;

    return 0;
}
