#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_OBJ 1000
#define MAX_WEIGHT 30

int objectWeight[MAX_OBJ];
int objectPrice[MAX_OBJ];
int numberOfObjects, numberOfPeople, peopleWeight, maxValue;
int MEMO[MAX_OBJ][MAX_WEIGHT];

/*
void printMat(int obj, int weight){
    for(int i=obj; i>=0; i--){
        for(int j=0; j<=weight; j++){
            cout << MEMO[i][j] << " ";
        }
        cout << endl;
    }
}
*/

int knapsackREC(int item, int weight){
    if(item < 0) return 0;
    if(weight <= 0) return 0;

    if(MEMO[item][weight] != -1)
        return MEMO[item][weight];

    if(objectWeight[item] > weight)
        MEMO[item][weight] = knapsackREC(item-1, weight);
    else
        MEMO[item][weight] = max(objectPrice[item] + knapsackREC(item-1, weight-objectWeight[item]), knapsackREC(item-1, weight));

    return MEMO[item][weight];
}

int main(){
    int numberOfTestCase;
    cin >> numberOfTestCase;
    while(numberOfTestCase--){
        cin >> numberOfObjects;
        for(int i=0; i<numberOfObjects; i++){
            cin >> objectPrice[i] >> objectWeight[i];
        }

        cin >> numberOfPeople;
        for(int j=0; j<numberOfPeople; j++){
            cin >> peopleWeight;
            memset(MEMO, -1, sizeof(MEMO));
            maxValue += knapsackREC(numberOfObjects-1, peopleWeight);
        }
        
        cout << maxValue << endl;
        //printMat(numberOfObjects-1, peopleWeight);
        maxValue = 0;
    }

    return 0;
}