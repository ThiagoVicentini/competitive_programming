#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int permutation[MAX];
int depth[MAX];

int max_(int *array, int start, int end){
    int max_index = start;
    for(int i=start+1; i < end; i++){
        if(array[i] > array[max_index])
            max_index = i;
    }

    return max_index;
}

void solve(int start, int end, int depth_){
    if (end-start >= 1){
        int mid = max_(permutation, start, end);
        depth[mid] = depth_;

        // divide
        solve(start, mid, depth_+1);
        solve(mid+1, end, depth_+1); 
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i<numbeOfTestCases; i++){
       // Input
        int lengthOfPermutation;
        cin >> lengthOfPermutation;
        for(int j=0; j<lengthOfPermutation; j++){
            cin >> permutation[j];
        }

        solve(0, lengthOfPermutation, 0);
        for(int j=0; j<lengthOfPermutation; j++){
            cout << depth[j]<< " ";
        }
        cout << endl;
    }

    return 0;
}