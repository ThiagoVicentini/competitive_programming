#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 3
#define VALOR 10

int moedas[MAX] = {1, 3, 4};

int MEMO[VALOR+1];

/*
int moedasIT(int v){
    for(int i=1; i<=v; i++){
        int menor = INT_MAX;
        for(int j=0; j< MAX; j++){
            if(i-moedas[j] >= 0)
                menor = min(MEMO[i-moedas[j]] + 1, menor);
        }
        MEMO[i] = menor;
    }
    return MEMO[v];
}
*/

int moedasREC(int v){
    if(v==0) return 0;
    if(v < 0) return INT_MAX-1;
    
    if(MEMO[v] != -1) 
        return MEMO[v];

    int menor = INT_MAX;
    for(int i=0; i<MAX; i++){
        menor = min(moedasREC(v-moedas[i])+1, menor);
    }
    MEMO[v] = menor;
    return menor;
}

int main(){

    memset(MEMO, -1, sizeof(MEMO));
    cout << "Qntd minima de moedas é: " << moedasREC(VALOR) << endl;

    //MEMO[0] = 0;
    //cout << "Qntd minima de moedas é: " << moedasIT(VALOR) << endl;

    return 0;
}