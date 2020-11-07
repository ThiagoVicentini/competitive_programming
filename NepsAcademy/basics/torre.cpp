#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int tabuleiro[N][N], linha[N], coluna[N];

    for(int i=0; i<N; i++){
        linha[i] = 0;
        coluna[i] = 0;
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin >> tabuleiro[i][j];
            linha[i] += tabuleiro[i][j];
            coluna[j] += tabuleiro[i][j];
        }

    int maxV=0, soma=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            soma += linha[i] + coluna[j] - 2*tabuleiro[i][j];
            if(soma > maxV)
                maxV = soma;
            soma=0;
        }
    }

    cout << maxV;

    return 0;
}
