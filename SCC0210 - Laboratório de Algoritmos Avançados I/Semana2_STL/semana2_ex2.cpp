#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    stack<char> s;
    string frase;
    cin >> frase;
    
    int size = frase.length() - 1;
    s.push(frase[size]);
    for(int i = size-1; i >= 0; i--){
        if(s.empty()){
          s.push(frase[i]);
        }
        else{
          if(s.top() == frase[i]){
              s.pop();
          }else{
              s.push(frase[i]);
          }
        }
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}