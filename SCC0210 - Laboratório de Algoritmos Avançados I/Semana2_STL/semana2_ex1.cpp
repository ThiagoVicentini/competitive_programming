#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string name, ip;
    map<string, string> mapa;
    while(n>0){
        cin >> name >> ip;
        mapa[ip] = name;
        n--;
    }

    string command;
    while(m>0){
        cin >> command >> ip;
        ip.pop_back();
        cout << command << " " << ip << "; #" << mapa[ip] << endl;
        m--;
    }

    return 0;
}