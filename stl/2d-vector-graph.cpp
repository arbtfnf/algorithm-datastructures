int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>indegree(N+1,0);
        vector<int>outdegree(N+1,0);
        for(auto &e: trust){
            indegree[e[1]]++;
            outdegree[e[0]]++;
        }
        int index = -1;
        for(int i=1;i<=N;i++){
            if(indegree[i]>=N-1 && outdegree[i]==0){
                return i;   
            }
        }
        return index;
    }