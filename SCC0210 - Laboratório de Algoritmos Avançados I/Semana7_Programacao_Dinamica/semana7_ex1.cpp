#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_COIN 100
#define MAX_SUM (int)10e6
#define mod (int)1e9 + 7

int moedas[MAX_COIN];
int numberOfCoins, desiredSum;
int MEMO[MAX_SUM];

/*
int sumREC(int sum){
    if(sum==0) return 1;
    if(sum<0) return 0;
    
    if(MEMO[sum] != -1)
        return MEMO[sum];

    int n=0;
    for(int i=0; i<numberOfCoins; i++)
        n += sumPD(sum-moedas[i])%mod;
    n %= mod;
    MEMO[sum] = n;
    return MEMO[sum];
}
*/

long long int sumIT(){
    for(int iSum=1; iSum<=desiredSum; iSum++){
        int nPossible=0;

        for(int coin=0; coin<numberOfCoins; coin++){
            if(iSum-moedas[coin] >= 0){
                nPossible += MEMO[iSum-moedas[coin]];
                nPossible %= (mod);
            }
        MEMO[iSum] = nPossible;
        }
    }
    return MEMO[desiredSum];
}

int main(){
    cin >> numberOfCoins >> desiredSum;
    for(int i=0; i<numberOfCoins; i++)
        cin >> moedas[i];

    MEMO[0] = 1;
    cout << sumIT() << endl;

    return 0;
}