#include "KitchenGraph.h"
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void KitchenGraph::addPath(string a, string b) {
    adj[a].push_back(b);
    adj[b].push_back(a); 
}

void KitchenGraph::shortestPath(string start, string end) {
    map<string, string> parent;
    queue<string> q;
    map<string, bool> visited;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        string cur = q.front(); q.pop();

if(cur == end) break;
for(auto n: adj[cur]){
            if(!visited[n]){
                visited[n] = true;
                parent[n] = cur;
                q.push(n);
            }
        }
    }

    vector<string> path; string cur=end;
    while(cur!= start){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout<<"\nShortest path from "<<start<<" to "<<end<<": ";
    for(auto p: path){
        cout<<p<<" ";
        cout<< endl;
    }
}
      
