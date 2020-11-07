//Thiago Henrique Vicentini
//Telegram: @ThiagoVicentini
//Discord: Anakin#8592

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int quadradro[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> quadradro[i][j];
    }

    int valor[2*N+2];
    int x=0;
    int soma=0;
    for(int i=0; i<4; i++){
        if(i<2){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    if(i==0)
                        soma += quadradro[j][k];
                    else if(i==1)
                        soma += quadradro[k][j];
                }
                valor[x] = soma;
                soma = 0;
                x++;
            }
        }
        else if(i==2){
            for(int j=0; j<N; j++)
                soma += quadradro[j][j];
            valor[x] = soma;
            soma = 0;
            x++;
        }
        else{
            int k=0;
            for(int j=N-1; j>=0; j--){
                soma += quadradro[j][k];
                k++;
            }
            valor[x] = soma;
            x++;
        }
    }

    for(int i=0; i<2*N+2; i++){
        if(valor[i] != soma){
            cout << -1;
            return 0;
        }
    }

    cout << soma;
    return 0;
}
