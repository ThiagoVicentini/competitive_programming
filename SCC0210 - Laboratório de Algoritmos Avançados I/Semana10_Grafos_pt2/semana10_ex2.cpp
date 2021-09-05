#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi vertices;
vector<vii> AdjList(100);

typedef enum {
    branco, cinza, preto
}TipoCor;

TipoCor cor[100];
int distancia[100];

int bfs(int u, int n){
    queue<int> q;

    distancia[u] = 0;
    q.push(u);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        cor[k] = cinza;

        for(int j=0; j<(int)AdjList[k].size(); j++){
            ii v = AdjList[k][j];
            if(cor[v.second] == branco){
                cor[v.second] = cinza;
                distancia[v.second] = distancia[k] + 1;
                q.push(v.second);
            }
        }
        cor[k] = preto;
    }
    return distancia[n];
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> a;
            ii v_a = make_pair(a, b);
            AdjList[a].push_back(v_a);
        }
    }

    int resp = bfs(1, n);
    if(resp == 0)
        cout << "IMPOSSIBLE";
    else
        cout << bfs(1, n) + 1<< endl;
    return 0;
}