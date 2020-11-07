#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, k;
    cin >> n >> k;
    if(k==1){
        cout << 1 << endl;
        return 0;
    }

    int cont=0;
    if(k==2 || k==4 || k==6 || k==8){
        while(n%4 != 1){
            if((n%4==2 && k==2) || (n%4==3 && k==4) || (n%4==0 && k==8) || (n%4==1 && k==6))
                cont++;
            n--;
        }
        cont += n/4;
        cout << cont << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}
