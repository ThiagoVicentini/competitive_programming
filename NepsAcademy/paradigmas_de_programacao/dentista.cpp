#include <iostream>
#include <algorithm>

#define MAX 10100

using namespace std;

struct c{
    int inicio, fim;
};

bool compara(c x, c y){
    return x.fim < y.fim;
}

c consultas[MAX];

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> consultas[i].inicio >> consultas[i].fim;

    sort(consultas, consultas+N, compara);

    int cont=0, livre=0;
    for(int i=0; i<N; i++){
        if(consultas[i].inicio >= livre){
            cont++;
            livre = consultas[i].fim;
        }
    }

    cout << cont << endl;

    return 0;
}
