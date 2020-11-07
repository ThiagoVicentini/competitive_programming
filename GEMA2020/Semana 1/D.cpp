#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    int print[3];
    cin >> a >> b >> c;
    if(a > b){
        if(a > c){
            print[0] = a; //maior
            if(c > b){
                print[1] = c; //meio
                print[2] = b; //menor
            }
            else{
                print[1] = b;
                print[2] = c;
            }
        }
        else{
            print[0] = c;
            print[1] = a;
            print[2] = b;
        }
    }
    else{
        if(b > c){
            print[0] = b;
            if(c > a){
                print[1] = c;
                print[2] = a;
            }
            else{
                print[1] = a;
                print[2] = c;
            }
        }
        else{
            print[2] = a;
            print[1] = b;
            print[0] = c;
        }
    }
    cout << print[2] << endl;
    cout << print[1] << endl;
    cout << print[0] << endl;

    return 0;
}
