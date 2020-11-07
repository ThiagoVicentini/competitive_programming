#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, T;
    cin >> N >> M;
    T = N*M;
    if(T%2 == 0)
        cout << T/2;
    else
        cout << T/2 + 1;

    return 0;
}
