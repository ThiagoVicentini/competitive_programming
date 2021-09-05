#include <cstring>
#include <iostream>

#define MAX 3002

using namespace std;

int main(){

    int n;
    cin >> n;
    long coolness[MAX];
    int coin=0;
    bool coolness_b[MAX+n];
    memset(coolness, 0, sizeof(coolness));
    memset(coolness_b, false, sizeof(coolness_b));
    
    for(int i=1; i<=n; i++){
        cin >> coolness[i];
        while(coolness_b[coolness[i]]){
            coolness[i]++;
            coin++;
        }
        coolness_b[coolness[i]] = true;
    }
    cout << coin << "\n";
    return 0;
}