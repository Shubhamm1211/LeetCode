class Solution {
public:
    void dfs(vector<vector<int>>&graph,int p,int node,vector<vector<int>>&res,vector<bool>&vis){
        vis[node]=1;
        for(auto x:graph[node]){
            if(!vis[x]){
                res[x].push_back(p);
                dfs(graph,p,x,res,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
        }
       for(int i=0;i<n;i++){
        vector<bool>vis(n,false);
        dfs(graph,i,i,res,vis);
       }
        
        for(int i=0;i<n;i++){
            sort(res[i].begin(),res[i].end());
        }
        return res;
    }
};