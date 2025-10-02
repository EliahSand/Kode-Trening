#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;

void spiral(ll t){
    ll y,x;
   
    for (int i = 0; i < t ;i++){
        ll box, add;
        add = 0;
        cin >> y >> x;
        if(y>x){
            box = (y-1)*(y-1);
            if(y%2 == 0){
                add = 2*y -x;
            }
            else {
                add = x;
            }
            cout << add + box << endl;
        } else {
            box = (x-1)*(x-1);
            if(x % 2 != 0){
                add = 2*x -y;
            } else{
                add = y;
            }
            cout << add + box << endl;
        }
        
    }

}

int main(){

    ll t;
    cin >> t;
    spiral(t);

    return 0;
}