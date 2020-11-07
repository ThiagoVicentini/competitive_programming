#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, p;
    cin >> p;
    if(p == 2){
        cout << 0;
    }
    else{
        x = (p+1)/2;
        y = (p-1)/2;
    }

    cout << 1 << endl;
    cout << x << " " << y << endl;
    return 0;
}
