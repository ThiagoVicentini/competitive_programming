#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
    int q_num;
    int period;
    int next_time;
}struct_query;

auto cmp = [](struct_query a, struct_query b){
    if(a.next_time == b.next_time){
      return a.q_num > b.q_num;
    }else{
      return a.next_time > b.next_time;
    }
};


int main(){

    string trash;
    vector<struct_query> q_array;
    while(cin >> s, s!= "#"){
      struct_query q;
      cin >> q.q_num >> q.period;
      q.next_time = q.period;
      q_array.push_back(q);
    }

    priority_queue<struct_query, vector<struct_query>, decltype(cmp)> pq(cmp);
    
    unsigned int k; cin >> k;
    int menor_id = 0;

    while(pq.size() < k){
        for(unsigned int i=0; i < q_array.size(); i++){
            if(q_array[i].next_time < q_array[menor_id].next_time)
                menor_id = i;
            else if(q_array[i].next_time == q_array[menor_id].next_time && q_array[i].q_num < q_array[menor_id].q_num)
                menor_id = i;
        }   
        pq.push(q_array[menor_id]);
        q_array[menor_id].next_time += q_array[menor_id].period; 
    }

    while(pq.size() > 0){
      cout << pq.top().q_num << endl;
      pq.pop();
    }

    return 0;
}