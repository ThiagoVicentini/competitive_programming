#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> vizinhos[N+2];

    int T, A, B;
    bool achou = false;
    vector<int>::iterator ptr;

    for(int i=0; i<M; i++){
        cin >> T >> A >> B;
        if(T==0){
            for(ptr = vizinhos[A].begin(); ptr < vizinhos[A].end(); ptr++){
                if(*ptr == B){
                    cout << 1 << endl;
                    achou = true;
                    break;
                }
            }

            if(!achou)
                cout << 0 << endl;
            achou = false;
        }
        else{
            vizinhos[A].push_back(B);
            vizinhos[B].push_back(A);
        }
    }

    return 0;
}
