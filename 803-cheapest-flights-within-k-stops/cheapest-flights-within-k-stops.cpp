class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> pq; // {dist,{node,stops}}
        pq.push({0,{src,0}});
        vector <vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        pq.push({0,{src,0}});
        vector<int> dis(n,1e8);
        while(!pq.empty()){
            auto x = pq.front();
            pq.pop();
            int d = x.first;
            int node = x.second.first;
            int s = x.second.second;
            if(s > k) continue;
            for(auto x : adj[node]){
                int adjn = x.first;
                int dd = x.second;
                if(d + dd < dis[adjn]){
                    dis[adjn] = d + dd;
                    pq.push({dis[adjn],{adjn,s + 1}});
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dis[i] == 1e8) dis[i] = -1;
        }
        return dis[dst];
    }
};