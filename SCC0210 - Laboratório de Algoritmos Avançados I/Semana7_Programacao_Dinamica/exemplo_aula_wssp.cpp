#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 3
#define W 6

int pesos[MAX] = {2, 2, 3};

int MEMO[MAX][W+1];
int MEMO2[MAX+1][W+1];

void printMat(int M[][W+1]){
    for(int i=MAX-1; i>=0; i--){
        for(int j=0; j<=W; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void printMat1(int M[][W+1]){
    for(int i=MAX; i>=0; i--){
        for(int j=0; j<=W; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int mochilaREC(int i, int w){
    if(i < 0) return 0;

    if(MEMO[i][w] != -1)
        return MEMO[i][w];

    if(pesos[i] > w)
        MEMO[i][w] = mochilaREC(i-1, w);
    else
        MEMO[i][w] = max(pesos[i] + mochilaREC(i-1, w-pesos[i]), mochilaREC(i-1, w));

    return MEMO[i][w];
}

int mochilaIT(int i, int w){
    for(int i=1; i<=MAX; i++){
        for(int p=0; p<=W; p++){
            if(pesos[i-1] > p)
                MEMO2[i][p] = MEMO2[i-1][p];
            else
                MEMO2[i][p] = max(pesos[i-1] + MEMO2[i-1][p-pesos[i-1]], MEMO2[i-1][p]);
        }
    }
    return MEMO2[MAX][W];
}

int main(){

    memset(MEMO, -1, sizeof(MEMO));
    cout << "Peso max da mochila = " << mochilaREC(MAX-1, W) << endl;
    printMat(MEMO);

    for(int i=0; i<=W; i++)
        MEMO2[0][i] = 0;
    cout << "Peso max da mochila = " << mochilaIT(MAX-1, W) << endl;
    printMat1(MEMO2);

    return 0;
}