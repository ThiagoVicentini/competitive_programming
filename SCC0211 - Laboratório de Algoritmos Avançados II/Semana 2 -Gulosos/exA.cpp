#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int start;
    int end;
}event;

bool sortByEnd(event e1, event e2){
    return (e1.end < e2.end);
}

vector<event> elements;
vector<event> possibleActivities;
int nPossibleActivities=1;

bool isPossible(int index_activity){
    if(elements[index_activity].start >= possibleActivities[nPossibleActivities-1].end){
        possibleActivities.push_back(elements[index_activity]);
        return true;
    }
    return false;
}

void schedule(int length){

    for (int i = 0; i<length; i++) {
        event e;
        cin >>  e.start >> e.end;
        elements.push_back(e);
    }

    sort(elements.begin(), elements.end(), sortByEnd);
    possibleActivities.push_back(elements[0]);

    for(int i=1; i<length; i++){
        if(isPossible(i))
            nPossibleActivities++;
    }

    cout << nPossibleActivities << endl;
    elements.clear();
    possibleActivities.clear();
    nPossibleActivities=1;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int numbeOfTestCases;
    cin >> numbeOfTestCases;

    for (int i = 0; i<numbeOfTestCases; i++){
        int numberOfActivities;
        cin >>  numberOfActivities;
        schedule(numberOfActivities);
    }

    return 0;
}