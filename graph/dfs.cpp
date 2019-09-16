#include <bits/stdc++.h>
using namespace std;

int n, e, x, y;
int vector<int> store[1000];
int visited[1000];
void dfs(int k){
    visited[k] = 1;
    cout << k << cout;
    for(auto it = store[k].begin(); it != store[k].end(); it++){
        if(!visited[*it]) dfs(*it);
    }
}

int main(){
    cin >> n >> e;

    for(int i=1; i<=e; i++){
        cin >> x >> y;
        store[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);    
    }
    return 0;
}
