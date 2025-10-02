#include <iostream>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<ll, ll> prefix_count; // Hash-map for å lagre antall forekomster av prefix-sum
    ll prefix_sum = 0;
    ll subCounter = 0;

    // Håndter sub-arrayer som starter fra første element
    prefix_count[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Sjekk om det finnes en tidligere prefix-sum slik at sub-array-sum == x
        if (prefix_count.find(prefix_sum - x) != prefix_count.end()) {
            subCounter += prefix_count[prefix_sum - x];
        }

        // Oppdater hash-mappen
        prefix_count[prefix_sum]++;
    }

    cout << subCounter << endl;
    return 0;
}