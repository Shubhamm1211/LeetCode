// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<pair<int,int>>adj[n];
//         for(auto it:roads){
//             adj[it[0]].push_back({it[1],it[2]});
//             adj[it[1]].push_back({it[0],it[2]});
//         }
//         priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
//         //{dist,node}
//         pq.push({0,0});
//         vector<int>dist(n,INT_MAX);
//         dist[0]=0;
//         vector<int>ways(n,0);
//         ways[0]=1;
//         while(!pq.empty()){
//             int dis=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             for(auto x:adj[node]){
//                 int wt=x.second;
//                 int adjnode=x.first;
//                 if(wt+dis<dist[adjnode]){
//                     dist[adjnode]=wt+dis;
//                     pq.push({dist[adjnode],adjnode});
//                     ways[adjnode]=ways[node];
//                 }
//                 else if(wt+dis==dist[adjnode]){
//                     ways[adjnode]=(ways[adjnode]+ways[node])%1000000007;
//                 }
//             }
//         }
//         if(ways[n-1]==0)return 0;
//         else return ways[n-1]%1000000007;
//     }
// };


// CHANGE TO INT TO LONG LONG


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        // {dist, node}
        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto x : adj[node]) {
                int wt = x.second;
                int adjnode = x.first;
                if (wt + dis < dist[adjnode]) {
                    dist[adjnode] = wt + dis;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                } else if (wt + dis == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % 1000000007;
                }
            }
        }

        return ways[n - 1] % 1000000007;
    }
};
