#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void permute(vector<string> words_dict, string &rule, int k, string output){
   if (k == (int)rule.size()) {
        cout << output << endl;
        return;
    }

    if (rule[k] == '#') {
        for (int i = 0; i < (int)words_dict.size(); i++){
            permute(words_dict, rule, k+1, output + words_dict[i]);
        }
    } else if (rule[k] == '0') {
        for (int i = 0; i < 10; i++){
            char digit = i + '0';
            permute(words_dict, rule, k+1, output + digit);
        }
    }
}

int main(){
    int n, m;
    vector<string> words_dict;
    string word, rule;    

    while(cin>>n){
        while(n--){
            cin >> word;
            words_dict.push_back(word);
        }

        cout << "--" << endl;

        cin >> m;
        while(m--){
            cin >> rule;
            permute(words_dict, rule, 0, "");
        }
        
        words_dict.clear();
    }

    return 0;
}