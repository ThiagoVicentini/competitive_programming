#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000

struct elephant{
    int weight;
    int qi;
};

vector<elephant> elephant_v;
int MEMO[MAX];
int maior = 1;

bool sort_e(elephant a, elephant b){
    return ((a.weight < b.weight) || ((a.weight == b.weight) && (a.qi > b.qi)));
}

int elefante_PD(){
    sort(elephant_v.begin(), elephant_v.end(), sort_e);

    for(int i = 1; i < (int)elephant_v.size(); ++i){
        MEMO[i] = 1;
        for(int j = i - 1; j >= 0; --j){
            int res = MEMO[j] + 1;
            if((elephant_v[i].weight > elephant_v[j].weight) && (elephant_v[i].qi < elephant_v[j].qi))
                MEMO[i] = max(res, MEMO[i]);
        }
        maior = MEMO[i] > maior ? MEMO[i] : maior;
    }

    return maior;
}

int main(){

    elephant e;
    while(cin >> e.weight >> e.qi)
        elephant_v.push_back(e);
    
    MEMO[0] = 1;
    cout << elefante_PD();
    return 0;
}