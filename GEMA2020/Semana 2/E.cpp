#include <bits/stdc++.h>

using namespace std;

int main (){
    int N, cont=0;
    cin >> N;

    string p;
    cin >> p;

    if(N==1){
        cout << 0;
        return 0;
    }

    int j = (N/2)-1;
    if(N%2 == 0){
        for(int i=N/2; i<N; i++){
            if(p[i] != p[j])
                cont++;
            j--;
        }
    }
    else{
        for(int i=1+(N/2); i<N; i++){
            if(p[i] != p[j])
                cont++;
            j--;
        }
    }

    cout << cont << endl;

    //-------------------------------------------
    int n; cin >> n;
    string s; cin >> s;

    int ans=0;
    for(int i=0, j=n-1; i<j; i++, j--){
        if(s[i] != s[j]){
            ans++;
        }
    }

    cout << ans << "\n";
    //-------------------------------------------
    
    return 0;
}
