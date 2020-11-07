#include <iostream>

using namespace std;

int main(){

    int N, num1, num2;
    cin >> N;
    cin >> num1;
    int cont = 1, max=-1;
    for(int i=1; i<N; i++){
        cin >> num2;
        if(num2 == num1)
            cont++;
        else{
            num1=num2;
            if(cont > max){
                max = cont;
            }
            cont = 1;
        }
    }
    if(cont > max)
        max = cont;
    cout << max;

    return 0;
}
