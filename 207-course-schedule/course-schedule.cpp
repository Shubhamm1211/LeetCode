class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<int> adj[v];     
        vector<int>indeg(v,0);                     
        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>topo;
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        if(topo.size()==v)return true;
        else return false;

    }
};