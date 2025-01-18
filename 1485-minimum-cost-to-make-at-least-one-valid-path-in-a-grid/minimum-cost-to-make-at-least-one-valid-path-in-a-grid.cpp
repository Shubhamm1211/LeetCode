class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 and m == 1){
            return 0;
        }
        vector <vector <int>> ans(n,vector<int> (m, 1e9));
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,0,0}); // {cost,i,j};
        vector <pair<int,int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!pq.empty()){
            int c = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + d[i].first;
                int nc = col + d[i].second;
                if(nr >= 0 and nr < n and nc >= 0 and nc < m){
                    int dir = grid[row][col];
                    int ncost = c + ((dir - 1 == i) ? 0 : 1);
                    if(ncost < ans[nr][nc]){
                        ans[nr][nc] = ncost;
                        pq.push({ncost, nr, nc});
                    }
                }
            }
        }
        return ans[n - 1][m - 1];
    }
};