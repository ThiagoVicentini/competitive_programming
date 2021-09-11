#include <bits/stdc++.h>

using namespace std;

vector<int> squares;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfSquares;
    cin >> numbeOfSquares;

    for (int i = 0; i < numbeOfSquares; i++) {
        int height;
        cin >> height;

        if(numbeOfSquares==1){
            cout << "Yes" << endl;
            continue;
        }

        if(i==0){
            squares.push_back(height);
            continue;
        }

        if(height > squares[i-1]){
            height--;
            squares.push_back(height);
        }else if(height == squares[i-1]){
            squares.push_back(height);
        }else{
            cout << "No" << endl;
            break;
        }

        if(i==numbeOfSquares-1)
            cout << "Yes" << endl;
    }

    return 0;
}