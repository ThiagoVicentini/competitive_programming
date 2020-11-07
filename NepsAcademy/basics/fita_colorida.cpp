#include <iostream>

using namespace std;

int main(){
    int N, i, j, k;
    cin >> N;

    int fita[N];

    for(i=0; i<N; i++)
        cin >> fita[i];

    int dir=100000, esq=100000;
    for(i=0; i<N; i++){
        if(fita[i] == -1){
            j=i+1;
            k=i-1;
            while(true){
                if(j<N){
                    if(fita[j] == 0){
                        dir = j-i;
                        break;
                    }
                }
                if(k>-1){
                    if(fita[k] == 0){
                        esq = i-k;
                        break;
                    }
                }

                j++;
                k--;
            }

            if(dir < esq)
                fita[i] = dir;
            else
                fita[i] = esq;

            dir=100000;
            esq=100000;
        }

        cout << fita[i];
        if(i!=N-1)
            cout << " ";
    }

    return 0;
}
