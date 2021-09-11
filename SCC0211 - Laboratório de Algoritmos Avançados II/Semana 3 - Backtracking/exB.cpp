#include <bits/stdc++.h>

using namespace std;

#define sizeBoard 10

vector<pair<int,int>> positions;
char board[sizeBoard][sizeBoard];
int maxMov = 0;

int movesBlack [4][2] = {   { 1, 1}, 
                            {-1,-1},
                            { 1,-1},
                            {-1, 1} };

int movesWhite [4][2] = {   { 2, 2}, 
                            {-2,-2},
                            { 2,-2},
                            {-2, 2} };

bool isPossibleMove(int x, int y, int i){
    if( (x+movesWhite[i][0] >= 0) and (x+movesWhite[i][0] < sizeBoard) )
        if( (y+movesWhite[i][1] >= 0) and (y+movesWhite[i][1] < sizeBoard) )
            if( board[x+movesBlack[i][0]][y+movesBlack[i][1]] == 'B' )
                if( board[x+movesWhite[i][0]][y+movesWhite[i][1]] == '#' )
                    return true;
    return false;
}

void backtrack(int x, int y, int mov){
    if(mov > maxMov)
        maxMov = mov;
    for(int i=0; i<4; i++){ // 4 possibles moviments (diagonals)            
        if(isPossibleMove(x, y, i)){
            board[x][y] = '#';
            board[x+movesBlack[i][0]][y+movesBlack[i][1]] = '#';
            board[x+movesWhite[i][0]][y+movesWhite[i][1]] = 'W';
            backtrack(x+movesWhite[i][0], y+movesWhite[i][1], mov+1);
            board[x][y] = 'W';
            board[x+movesBlack[i][0]][y+movesBlack[i][1]] = 'B';
            board[x+movesWhite[i][0]][y+movesWhite[i][1]] = '#';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i<numbeOfTestCases; i++){
        // Input
        for(int j=0; j<sizeBoard; j++){
            for(int k=0; k<sizeBoard; k++){
                cin >> board[j][k];
                if(board[j][k] == 'W')
                    positions.push_back(make_pair(j, k));
            }   
        }

        // Backtracking
        for(int k=0; k<(int)positions.size(); k++){
            backtrack(positions[k].first, positions[k].second, 0);
        }
        
        // Output
        cout << maxMov << endl;

        positions.clear();
        maxMov=0;
    }

    return 0;
}