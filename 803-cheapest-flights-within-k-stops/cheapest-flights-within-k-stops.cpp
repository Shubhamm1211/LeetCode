class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        //{stops,{node,dist}};
        vector<int>dis(n,1e9);
        while(!q.empty()){
            auto itt=q.front();
            int stop=itt.first;
            int node=itt.second.first;
            int wt=itt.second.second;
            q.pop();
            if(stop>k)continue;
            for(auto it:adj[node]){
                int adjn=it.first;
                int w2=it.second;
                if(wt+w2<dis[adjn] && stop<=k){
                    dis[adjn]=wt+w2;
                    q.push({stop+1,{adjn,w2+wt}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};