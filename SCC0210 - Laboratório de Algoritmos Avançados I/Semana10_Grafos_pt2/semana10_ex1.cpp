#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> ii; // vertice e peso
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

typedef enum {
    branco, cinza, preto
}TipoCor;
typedef vector<TipoCor> vc;

vc cor;
vb visitado;

vector<vii> AdjList(100001);
priority_queue<ii> pq; // peso e vertice -> max heap -> precisa botar peso negativo

int V;
int A;

int bfs(int u){
    cor.assign(V+1, branco);
    int cont=1;

    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        cor[k] = cinza;

        for(int j=0; j<(int)AdjList[k].size(); j++){
            ii v = AdjList[k][j];
            if(cor[v.first] == branco){
                cont++;
                cor[v.first] = cinza;
                q.push(v.first);
            }
        }
        cor[k] = preto;
    }
    return cont;
}

void process(int u){
    visitado[u] = true;
    for(int i=0; i<(int)AdjList[u].size(); i++){
        ii elem = AdjList[u][i];
        int v = elem.first;
        int peso = elem.second;

        if(!visitado[v]){
            pq.push(ii(-peso, -v));
        }
    }
}

int prim(int u){

    visitado.assign(V+1, false);
    process(u); // consulta os adjacentes v de u e coloca na fila de prioridade se nao visitado
    int custo = 0;

    while(!pq.empty()){
        ii elem = pq.top(); pq.pop();
        int v = -elem.first;
        int peso = -elem.second;

        if(!visitado[v]){
            custo += peso;
            process(v);
        }
    }
    return custo;
}

int main(){
    cin >> V;
    cin >> A;
    int v, u, w;

    for(int i=0; i<A; i++){
        cin >> v >> u >> w;
        AdjList[u-1].push_back(ii(v-1, w));
        AdjList[v-1].push_back(ii(u-1, w));
    }

    int resp = bfs(0);
    if(resp != V)
        cout << "IMPOSSIBLE\n";
    else
        cout << prim(0) << endl;
    return 0;
}