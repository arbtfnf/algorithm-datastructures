#include <bits/stdc++.h>
using namespace std;

int n, e, x, y;
vector<int> store[1000];
int visited[1000];
queue<int> q;

void bfs(int k){
    visited[k] = 1;
    for(auto it = store[k].begin(); it != store[k].end(); it++){
        if(visited[*it] == 0){
            q.push(*it);
            cout << *it << endl;
            visited[*it] = 1;
        }
        int x = q.front();
        q.pop();
        bfs(x); 
    }
}

int main(){
    cin >> n >> e;

    for(int i=1; i<=e; i++){
        cin >> x >> y;
        store[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]) bfs(i);    
    }
    return 0;
}
