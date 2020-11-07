#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);

    int N;
    double n1, n2;
    cin >> n1 >> n2;
    cout << pow(n1, n2);

    return 0;
}
