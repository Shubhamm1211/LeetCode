class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        //{len,{row,col}}
        pq.push({1,{0,0}});
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        dis[0][0] = 1;
        int dr[8] = {-1,1,0,1,1,-1,0,-1};
        int dc[8] = {0,1,1,-1,0,1,-1,-1};
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int d = x.first;
            int row = x.second.first;
            int col = x.second.second;
            for(int i = 0; i < 8; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] == 0){
                    if(d + 1 < dis[nr][nc]){
                        dis[nr][nc] = d + 1;
                        pq.push({dis[nr][nc], {nr,nc}});
                    }
                }
            }
        }
        if(dis[n - 1][n - 1] == 1e9) return -1;
        return dis[n - 1][n - 1];
    }
};