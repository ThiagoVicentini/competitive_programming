#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

int pessoas[MAX];
int iguais[MAX];

int main(){
    int N;
    cin >> N;
    string p;
    for(int i=0; i<N; i++){
        cin >> p;
        pessoas[i] = p.size();
        for(int j=i-1; j>=0; j--){
            if(pessoas[j] == pessoas[i]){
                iguais[i]++;
                iguais[j]++;
            }
        }
    }

    int maior=0;

    for(int i=1; i<N; i++){
        if(iguais[i] > iguais[maior]){
            maior = i;
        }
    }

    cout << pessoas[maior];


//==========================================================
    int n; cin >> n;
    int freq[1005] = {0};

    for(int i=0; i<n; i++){
        string s; cin >> s;
        freq[s.size()-1]++;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(freq[i] > freq[ans]){
            ans = i;
        }
    }

    cout << ans << "\n";
//==========================================================

    





    return 0;
}
