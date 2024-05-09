class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjn=it.first;
                int w2=it.second;
                if(wt+w2<dis[adjn]){
                    dis[adjn]=wt+w2;
                    q.push({wt+w2,adjn});
                }
            }
        }
        int maxi=*max_element(dis.begin()+1,dis.end());
        if(maxi==1e9)return -1;
        return maxi;
    }
};