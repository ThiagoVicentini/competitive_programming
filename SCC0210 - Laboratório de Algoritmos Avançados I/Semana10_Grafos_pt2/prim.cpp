#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> ii; // vertice e peso
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

vector<vii> AdjList(500);

int V;
int A;

priority_queue<ii> pq; // peso e vertice -> max heap -> precisa botar peso negativo

vb visitado;
vi dist;

void process(int u){
    visitado[u] = true;
    for(int i=0; i<AdjList[u].size(); i++){
        ii elem = AdjList[u][i];
        int v = elem.first;
        int peso = elem.second;

        if(!visitado[v]){
            pq.push(ii(-peso, -v));
        }
    }
}


int prim(int u){

    visitado.assign(V, false);
    process(u); // consulta os adjacentes v de u e coloca na fila de prioridade se nao visitado
    int custo = 0;

    while(!pq.empty()){
        ii elem = pq.top(); pq.top();
        int v = -elem.second;
        int peso = -elem.first;

        if(!visitado[v]){
            custo += peso;
            process(v);
        }
    }

}

int main(){
    cin >> V;
    cin >> A;

    int v, u, w;
    for(int i=0; i<A; i++){
        cin >> v >> w >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    //printAdjList(V);
    printf("O valor da MST eh %d\n", prim(5));
    return 0;
}