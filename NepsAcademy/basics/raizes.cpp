#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);


    int N;
    double num;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        cout << sqrt(num) << endl;
    }

    return 0;
}
