class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> adj[n];
        for(int i = 0; i < n; i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }
        vector <int> vis(n,0);
        vector <int> topo;
        vector <int> indeg(n,0);
        for(int i = 0; i < n; i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue <int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};