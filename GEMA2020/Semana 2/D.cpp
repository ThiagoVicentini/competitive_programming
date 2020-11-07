#include <bits/stdc++.h>

using namespace std;

int main (){

    int N, a, cont=0;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> a;
        if(a%2 == 0)
            cont++;
    }

    cout << cont;

    return 0;
}
