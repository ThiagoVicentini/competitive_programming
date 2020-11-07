#include <iostream>

using namespace std;

int main(){
    int N, i;
    cin >> N;

    int tabuleiro[N], resultado[N];
    for(i=0; i<N; i++)
        cin >> tabuleiro[i];
    cout << "\n\n";
    int cont=0;
    for(i=0; i<N; i++){
        if(i != 0)
            if(tabuleiro[i-1] == 1)
                cont++;

        if(tabuleiro[i] == 1)
            cont++;

        if(i != N-1)
            if(tabuleiro[i+1] == 1)
                cont++;

        resultado[i] = cont;
        cout << resultado[i] << endl;
        cont = 0;
    }

    return 0;
}
