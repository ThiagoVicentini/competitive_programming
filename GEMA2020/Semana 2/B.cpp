#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

int valores[MAX];

int main(){

    int N;
    cin >> N;

    int maior = 0;
    int menor = INT_MAX;
    for(int i=0; i<N; i++){
        cin >> valores[i];
        if(valores[i] > maior){
            maior = valores[i];
        }
        if(valores[i] < menor){
            menor = valores[i];
        }
    }

    cout << maior-menor << endl;
    return 0;
}
