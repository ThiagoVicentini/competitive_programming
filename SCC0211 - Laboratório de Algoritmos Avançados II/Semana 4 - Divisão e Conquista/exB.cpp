#include <bits/stdc++.h>

using namespace std;

#define MAX 131075

char goodString[MAX];

int solve(int start, int end, char letra){

    if(end-start <= 1){
        if(goodString[start] != letra)
            return 1;
        return 0;
    }

    int mid = (end+start)/2;

    // Caso 1: Considerando que o lado esquerdo deve ser a metade completa de letras e o lado direito deve ser a metade (letra+1)goodString
    int flag1=0;
    for(int i=start; i<mid; i++)
        if(goodString[i]!=letra)
            flag1++;

    int count1 = solve(mid, end, letra+1); // Lado direito (letra+1)goodString

    // Caso 2: Considerando o oposto do caso 1
    int flag2=0;
    for(int i=mid; i<end; i++)
        if(goodString[i]!=letra)
            flag2++;

    int count2 = solve(start, mid, letra+1); // Lado direito (letra+1)goodString

    if( (flag1+count1) < (flag2+count2) )
        return (flag1+count1);
    return (flag2+count2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i<numbeOfTestCases; i++){
       // Input
        int lengthOfString;
        cin >> lengthOfString;
        for(int j=0; j<lengthOfString; j++)
            cin >> goodString[j];
        
        cout << solve(0, lengthOfString, 'a') << endl;
    }

    return 0;
}