#include <bits/stdc++.h>

using namespace std;

#define MAX 20
#define len 3

vector<string> words;
char table[MAX][MAX];
int numberOfCharacters;

int moves [8][2] = { {-1, 0},       
					 { 1, 0},
					 { 0,-1},
					 { 0, 1},
					 { 1, 1}, 
					 {-1,-1},
					 { 1,-1},
					 {-1, 1} };

bool sortByLenghtAndASCII(string s1, string s2){
    int l1 = s1.size(), l2 = s2.size();
    if(l1 != l2)
        return (l1 < l2);

    return (s1 < s2);
}

bool isAscending(char *word, int k, int x, int y, int i){
    if(word[k-1] < table[x+moves[i][0]][y+moves[i][1]])
        return true;
    return false;
}

bool isPossibleMove(int x, int y, int i){
    if( (x+moves[i][0]>=0) and (x+moves[i][0]<numberOfCharacters) )
        if( (y+moves[i][1]>=0) and (y+moves[i][1]<numberOfCharacters) )
            return true;
    return false;
}

void findWords(char *word, int k, int x, int y){
    if(k >= len){ // only words with size >= N counts
        word[k] = '\0';
        words.push_back(word);
    }
    if(k < numberOfCharacters*numberOfCharacters){ // words has max N² length
        for(int i=0; i<8; i++){ // 8 possibles moviments            
            if(isPossibleMove(x, y, i)){
                if(isAscending(word, k, x, y, i)){
                    word[k] = table[x+moves[i][0]][y+moves[i][1]];
                    findWords(word, k+1, x+moves[i][0], y+moves[i][1]);
                }   
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i<numbeOfTestCases; i++){
        // Input
        cin >> numberOfCharacters;
        for(int j=0; j<numberOfCharacters; j++){
            for(int k=0; k<numberOfCharacters; k++){
                cin >> table[j][k];
            }
        }
        
        // Backtracking
        char word[MAX*MAX + 1];
        for(int j=0; j<numberOfCharacters; j++){
            for(int k=0; k<numberOfCharacters; k++){
                word[0] = table[j][k];
                findWords(word, 1, j, k);
            }
        }
        
        // Output
        if(!words.empty()){
            sort(words.begin(), words.end(), sortByLenghtAndASCII);
            words.erase(unique(words.begin(), words.end()), words.end());

            for(int j=0; j<(int)words.size(); j++){
                cout << words[j] << endl;
                //if(j!=(int)words.size()-1 or i!=numbeOfTestCases-1)
                //    cout << endl;
            }
        }
        if(i!=numbeOfTestCases-1)
            cout << endl;
        words.clear();
    }

    return 0;
}