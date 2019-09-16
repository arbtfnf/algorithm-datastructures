#include <bits/stdc++.h>
using namespace std;

int n, e, x, y;
int vector<int> store[1000];
int visited[1000];
int ndeg[1000];
queue<int> q;

void topo(){
    for(int i=1; i<=n; i++){
        if(!ndeg[i])    q.push(i);
    }
    int k = q.front();
    cout << k << endl;
    q.pop();


   for(auto it = store[k].begin(); it != store[k].end(); it++){
       ndeg[*it]--;
   }
}

int main(){
    cin >> n >> e;

    for(int i=1; i<=e; i++){
        cin >> x >> y;
        store[x].push_back(y);
        ndeg[y]++;
    }
    topo();
    return 0;
}
