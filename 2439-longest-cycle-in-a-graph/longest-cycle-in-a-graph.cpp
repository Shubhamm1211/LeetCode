class Solution {
public:
    void toposort(vector<int>&indeg,vector<int>&topo,vector<int>adj[]){
        queue<int>q;
        int n=indeg.size();
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
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
    }
    int bfs(int i,vector<int>&vis,vector<int>adj[]){
        vis[i]=1;
        int count=0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    count++;
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return count;
    }
    int longestCycle(vector<int>& edges) {
        vector<int>topo;
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        toposort(indeg,topo,adj);
        for(auto it:topo){
            vis[it]=1;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                maxi=max(bfs(i,vis,adj),maxi);
            }
        }
        if(maxi==INT_MIN)return -1;
        else return maxi+1;
    }
};