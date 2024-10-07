class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        for (auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode,vis,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {
        vector<int>adj[n];
        for(int i = 0; i < v.size(); i++){
            adj[v[i][0]].push_back(v[i][1]);
        }
        // for(int i = 0; i < n; i++){
        //     cout << i << " : " ;
        //     for(auto x: adj[i]){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        vector <int> vis(n,0);
        dfs(k, vis, adj);
        // vector <bool> sus(n,false);
        // for(int i = 0; i < n; i++){
        //     if(vis[i] == 1){
        //         sus[i] = true;
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     if(vis[i] == 0){
        //         for(auto x: adj[i]){
        //             if(vis[x] == 1){
        //                 sus[x] = false;
        //             }
        //         }
        //     }
        // }
        // vector <int> ans;
        // for(int i = 0; i < n; i++){
        //     if(sus[i] == false){
        //         ans.push_back(i);
        //     }
        // }
        bool sus = true;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                for(auto x : adj[i]){
                    if(vis[x] == 1) sus = false;
                }
            }
        }
        vector <int> ans;
        if(sus){
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};