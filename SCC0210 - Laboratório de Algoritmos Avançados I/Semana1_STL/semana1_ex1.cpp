#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct{
    string name;
    int priority;
    int order;
}individual;

auto cmp = [](individual a, individual b){
    if(a.priority == b.priority){
      return a.order > b.order;
    }else{
      return a.priority > b.priority;
    }
};

int main(){
    int n;
    cin >> n;

    individual p;
    string role;
    int order = 0;
 
    priority_queue<individual, vector<individual>, decltype(cmp)> q(cmp);

    for(int i=0; i<n; i++){
        cin >> p.name >> role;
        p.order = order;
        order++;

        if(role == "rat") p.priority = 1;
        else if(role == "woman" or role == "child") p.priority = 2;
        else if(role == "man") p.priority = 3;
        else p.priority = 4;

        q.push(p);
    }

    while(!q.empty()){
        cout << q.top().name << endl;
        q.pop();
    }

    return 0;
}