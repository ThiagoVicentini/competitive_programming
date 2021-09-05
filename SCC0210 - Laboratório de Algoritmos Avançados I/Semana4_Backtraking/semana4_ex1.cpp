#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool inverse (int i,int j) { return (i>j); }

vector<int> list;
vector<vector<int>> output;

void search(vector<int> subset, int n, int t, int k){
    if(k == n){
        int sum = 0;
        for(int x: list)
            sum += x;

        if(sum == t){
            bool aux = false;
            sort(list.begin(), list.end(), inverse);
            for(unsigned int i=0; i<output.size(); i++)
                if(output[i] == list)
                    aux = true;
            if(!aux){
                output.push_back(list);
                vector<int>::iterator it = list.begin();
                for(; ; it++){
                    if(it == list.end()-1){
                        cout << *it << "\n";
                        break;
                    }else
                        cout << *it << "+";
                }
            }
        }
    }else{
        list.push_back(subset[k]);
        search(subset, n, t, k+1);
        list.pop_back();
        search(subset, n, t, k+1);
    }
}

int main(){
    int t, n;
    vector<int> subset;
    cin >> t >> n;
    while(t!=0 and n!=0){
        for(int i=0; i<n; i++){
            int aux;
            cin >> aux;
            subset.push_back(aux);
        }
        cout << "Sums of " << t << ":\n";
        search(subset, n, t, 0);
        if(output.size() == 0){
            cout << "NONE" << endl;
        }
        subset.clear();
        list.clear();
        output.clear();
        cin >> t >> n;
    }
    
    return 0;
}