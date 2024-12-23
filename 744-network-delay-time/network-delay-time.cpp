class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v,t});
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        //{wt,node}
        vector<int> dis(n + 1, 1e9);
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int d = x.first;
            int node = x.second;
            for(auto it : adj[node]){
                if(d + it.second < dis[it.first]){
                    dis[it.first] = d + it.second;
                    pq.push({dis[it.first] ,it.first});
                }
            }
        }
        int ans = *max_element(begin(dis) + 1, end(dis));
        if(ans == 1e9) return -1;
        return ans;
    }
};