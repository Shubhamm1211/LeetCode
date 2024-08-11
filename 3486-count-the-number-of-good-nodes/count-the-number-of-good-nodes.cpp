class Solution { 
    int dfs(int node, int parent, vector<int> adj[], int& ans) {
        int size = -1, isGoodNode = 1, subtreeSize = 0;
        for(auto child : adj[node]) {
            if(child != parent) {
                int sub = dfs(child,node,adj,ans);
                subtreeSize += sub; 
                if(size == -1) {
                    size = sub; 
                }
                else if(size != sub) {
                    isGoodNode = 0; 
                }
            }
        }
     ans += isGoodNode; 
     return 1 + subtreeSize; 
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size(), ans = 0;
        vector<int> adj[n+1];
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }  
     dfs(0,-1,adj,ans);
     return ans;
    }
};