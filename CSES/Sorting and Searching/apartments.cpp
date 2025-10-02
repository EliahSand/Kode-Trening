#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll nrOfApplicants,nrOfApartments,allowedDiff;

    vector<ll> applicants, apartments;

    cin >> nrOfApplicants >> nrOfApartments >> allowedDiff;

    ll applicant, apartment;

    for(int i = 0; i < nrOfApplicants; i++){
        cin >> applicant;
        applicants.push_back(applicant);
    }

    for(int i = 0; i < nrOfApartments; i++){
        cin >> apartment;
        apartments.push_back(apartment);
    }
    //sort(applicants.begin(),applicants.end());
    //sort(apartments.begin(), apartments.end());
    
    ll counter = 0;
    ll i,j;

    while (i < applicants.size() && j < apartments.size()){
        if(abs(applicants[i] - apartments[j]) <= allowedDiff){
            //this is a match
            counter++;
            j++;
            i++;
        } else if (apartments[j] < applicants[i] - allowedDiff){
            //apartment to small, move on to the next apartment
            j++;
        } else {
            //next applicant
            i++;
        }
    }

    cout << counter << endl;

    return 0;
}

/*
Time complexity:
sorting the lists takes nlogn and mlogm time -> O(nlogn + mlogn)

spatial compex:
for each array:n , m
O(max(m + n))*/