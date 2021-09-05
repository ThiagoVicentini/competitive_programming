#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    string digit;
    int f[10];

    cin >> n;
    cin >> digit;
    for(int i=1; i<10; i++){
        cin >> f[i];
    }

    bool lock = false, start = false;
    for(int i=0; i<n; i++){
        if(start){
            if(!lock){
                int digit_ = (int)(digit[i]-48); 
                if(f[digit_] > digit_){
                    digit[i] = (char)(f[digit_] + 48);
                }else 
                    lock = true;
            }else 
                break;
        }else{
            int digit_ = (int)(digit[i]-48); 
            if(f[digit_] > digit_){
                digit[i] = (char)(f[digit_] + 48);
                start = true;
            }
        }
    }

    cout << digit << '\n';

    return 0;
}