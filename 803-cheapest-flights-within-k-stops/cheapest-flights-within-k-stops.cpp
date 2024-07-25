class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});//{stops,{node,dist}}
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();
            if(stops>k)continue;
            for(auto x:adj[node]){
                int adjnode=x.first;
                int wt=x.second;
                if(wt+dist<dis[adjnode] ){
                    dis[adjnode]=wt+dist;
                    q.push({stops+1,{adjnode,dis[adjnode]}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};