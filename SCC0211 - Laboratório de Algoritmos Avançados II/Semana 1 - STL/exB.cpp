#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> databaseSystem;

void validate(string request){
    if(databaseSystem.insert({request, 0}).second){
        cout << "OK" << endl;
    }else{
        databaseSystem[request]++;
        cout << request << databaseSystem[request] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i < numbeOfTestCases; i++) {
        string request;
        cin >> request;
        validate(request);
    }

    return 0;
}