#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int grafo[N+1][N+1];
    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++)
            grafo[i][j] = 0;

    int T, A, B;

    for(int i=0; i<M; i++){
        cin >> T >> A >> B;
        if(T==0){
            if(grafo[A][B] == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else{
            grafo[A][B] = 1;
            grafo[B][A] = 1;
        }
    }

    return 0;
}
