#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

#define MAX 500

using namespace std;

typedef pair<int, int> coord;

bool maze[MAX][MAX];
int mazeSize;
coord endPos;
map<coord, bool> visited;

int moves[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // down, right, up, left

typedef struct {
    int x;
    int y;
    int cost;
    int depth;
} Node;

auto cmp = [](Node n1, Node n2){
        return n1.cost > n2.cost;
};

int h(Node current){
    return abs(endPos.first - current.x) + abs(endPos.second - current.y);
}

bool equal(Node current){
    return (current.x == endPos.first and current.y == endPos.second);
}

bool isValidPos(Node currentPos, int n) {
    int x = currentPos.x;
    int y = currentPos.y;
    if(x < 0 || x >= n || y < 0 || y >= n || !maze[x][y] || visited[make_pair(x,y)])
        return false;
    visited[make_pair(x,y)] = true;
    return true;
}

int bfs(coord startPos, int n){
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    Node current, next;

    current.x = startPos.first;
    current.y = startPos.second;
    current.depth = 0;
    current.cost = current.depth + h(current);

    pq.push(current);

    while(!pq.empty()){
        current = pq.top();
        pq.pop();

        if(equal(current))
            return current.depth;

        for(int i = 0; i < 4; i++) {
            next.x = current.x + moves[i][0];
            next.y = current.y + moves[i][1];
            if(isValidPos(next, n)) {
                next.depth = current.depth + 1;
                next.cost = next.depth + h(next);
                pq.push(next);
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]){
   
    int numberOfTests, x, y;
    coord startPos;

    cin >> numberOfTests;
    while(numberOfTests--){
        cin >> mazeSize;
        
        cin >> x >> y;
        startPos = make_pair(x, y);

        cin >> x >> y;
        endPos = make_pair(x, y);

        for(int i=0; i<mazeSize; i++)
            for(int j=0; j<mazeSize; j++)
                cin >> maze[i][j];


        int ret = bfs(startPos, mazeSize);
        visited.clear();
        if(ret == -1)
            cout << "Caminho Inexistente.\n";
        else
            cout << "Nro de posicoes: " << ret + 1 << endl;
    }

    return 0;   
}