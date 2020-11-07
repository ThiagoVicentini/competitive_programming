#include <iostream>

using namespace std;

int main(){
    int N, i, cont=0;
    cin >> N;

    int num[N];
    for(i=0; i<N; i++)
        cin >> num[i];

    for(i=0; i<N; i++){
        if(num[i] == 1 and i+2 < N){
            if(num[i+1] == 0){
                if(num[i+2] == 0){
                    cont++;
                }
            }
        }
    }
    cout << cont;
    return 0;
}
