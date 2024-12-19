class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> col(n,-1);
        for(int i = 0; i < n; i++){
            if(col[i] == -1){
                queue<int> q;
                q.push(i);
                col[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto x : graph[node]){
                        if(col[x] == -1){
                            col[x] = !col[node];
                            q.push(x);
                        }
                        else if(col[x] == col[node]) return false;
                    }
                }
            }
        }
        for(auto x : col) cout << x << " ";
        return true;
    }
};