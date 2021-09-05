#include <bits/stdc++.h>

using namespace std;

void restore_permutation(int length){
    unordered_set<int> p;
    vector<int> elements;
    for (int i = 0; i < length*2; i++) {
        int element;
        cin >>  element;
        if(p.insert(element).second == 1){
            elements.push_back(element);
        }
    }

    for (auto i = elements.begin(); i != elements.end(); ++i)
        cout << *i << " ";
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i < numbeOfTestCases; i++) {
        int lengthOfPermutation;
        cin >>  lengthOfPermutation;
        restore_permutation(lengthOfPermutation);
    }


    return 0;
}