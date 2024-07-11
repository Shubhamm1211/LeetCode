class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<int>adj[n];
        for(int i=0;i<v.size();i++){
            adj[v[i][1]].push_back(v[i][0]);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        if(topo.size()==n)return true;
        else return false;
    }
};