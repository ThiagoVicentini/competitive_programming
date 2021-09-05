#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii; // vertice v e peso w
typedef vector<ii> vii; 
typedef vector<bool> vB;
vector<vii> AdjList(200);

int V;
int A;

vB visitado;

void printAdjList(){
    for(int i=0; i<V; i++){
        printf("%d: ", i+1);
        for(int j=0; j<AdjList[i].size(); j++){
            ii v = AdjList[i][j];
            printf("(%d, %d) -> ", v.first+1, v.second);
        }
        cout << endl;
    }
}

void dfs(int u){
    cout << u+1 << " ";
    visitado[u] = true;;

    for(int i=0; i<AdjList[u].size(); i++){
        ii v = AdjList[u][i];
        if(!visitado[v.first])
            dfs(v.first);
    }
}

void bfs(int s){
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
		printf("%d ", u+1);

		for(int i=0; i<AdjList[u].size(); i++){
			ii v = AdjList[u][i];
			if(dist[v.first] == INF){
				dist[v.first] = dist[u] + 1;
				q.push(v.first);
			}
		}
	}
}

int main(){
    cin >> V;
    int u, v;
    while(cin >> u >> v){
        AdjList[u-1].push_back(ii(v-1, 1));
        AdjList[v-1].push_back(ii(u-1, 1));
    }
    printAdjList();
	visitado.assign(V, false);
    dfs(0);
	cout << endl;
	bfs(0);
	cout << endl;

	return 0;
}