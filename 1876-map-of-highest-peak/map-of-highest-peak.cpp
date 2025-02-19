class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector <vector <int>> vis(n,vector<int>(m,0));
        vector <vector <int>> ans(n,vector<int>(m));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[r][c] = dist;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc]){
                    q.push({{nr,nc},dist + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};