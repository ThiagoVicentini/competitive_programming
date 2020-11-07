#include <iostream>

using namespace std;

int main(){
    bool lampA = false;
    bool lampB = false;

    int N;
    cin >> N;

    int op;
    for(int i=0; i<N; i++){
        cin >> op;
        if(op == 1){
            lampA = !lampA;
        }
        else{
            lampA = !lampA;
            lampB = !lampB;
        }
    }
    if(lampA)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    if(lampB)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
