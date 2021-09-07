#include <bits/stdc++.h>

using namespace std;

map<int, int> goodArray;
int ocorrencia[7];

int main(){
    goodArray[4]  = 0;
    goodArray[8]  = 1;
    goodArray[15] = 2;
    goodArray[16] = 3;
    goodArray[23] = 4;
    goodArray[42] = 5;

    int n; cin >> n;
    for (int i = 0; i<n; i++){
        int a; cin >> a;

        if (goodArray[a] == 0)
            ocorrencia[goodArray[a]]++;
        
        else if(ocorrencia[goodArray[a]-1] > 0){
            
            ocorrencia[goodArray[a]]++;
            ocorrencia[goodArray[a]-1]--;
            
        }
    }

    cout << n - 6*ocorrencia[5] << endl;
    return 0;
}