class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>> >pq; //{dist,node}
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int wt=it.second;
                int adjnode=it.first;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int maxi=*max_element(dist.begin()+1,dist.end());
        if(maxi!=1e9)return maxi;
        else return -1;
    }
};