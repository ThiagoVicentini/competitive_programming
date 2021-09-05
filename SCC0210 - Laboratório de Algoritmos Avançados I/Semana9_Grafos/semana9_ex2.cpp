#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
vb visitado;
vi vertices;
vector<vi> AdjList(5005);
int V;

int bfs(int u){
    visitado.assign(V, false);
    queue<int> q;
    q.push(u);
    int contador = 1;

    while(!q.empty()){
        int k = q.front(); q.pop();
        visitado[u] = true;

        for(int j=0; j<(int)AdjList[k].size(); j++){
            int v = AdjList[k][j];
            if(!visitado[v]){
                visitado[v] = true;
                q.push(v);
                contador++;
            }
        }
    }
    return contador;
}


int main(){
    unsigned int numberOfUsers, numberOfGroups;
    cin >> numberOfUsers >> numberOfGroups;
    
    V = n;
    Graph graph(numberOfUsers);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int a;
            cin >> a;
            vertices.push_back(a);
            for(int u=0; u<(int)vertices.size(); u++){
                if(vertices[u] != a){
                    AdjList[vertices[u]].push_back(a);
                    AdjList[a].push_back(vertices[u]);
                }
            }
        }
        vertices.clear();
    }


    int num_vertices = bfs(1);
    if(num_vertices == n){
        for(int i = 1; i<=n; i++)
            printf("%d ", n);
        cout << endl;
    }
    else{
        for(int i = 1; i<=n; i++)
            printf("%d ", bfs(i));
        cout << endl;
    }

    return 0;
}