class Solution {
public:
    bool dfs(int node, int co, vector<int> &col, vector <vector <int>> & adj){
        col[node] = co;
            for(auto x : adj[node]){
                if(col[x] == -1){
                    if(dfs(x,!co,col,adj) == false) return false;
                }
                else if(col[x] == col[node]) return false;
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> col(n, -1);
        for(int i = 0; i < n; i++){
            if(col[i] == -1){
                if(dfs(i,0,col,graph) == false) return false;
            }
        }
        return true;
    }
};