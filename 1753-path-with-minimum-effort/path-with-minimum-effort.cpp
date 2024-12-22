class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dis(n, vector<int>(m,1e8));
        dis[0][0] = 0;
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater <pair<int,pair<int,int>>> >pq;
        pq.push({0,{0,0}}); // {wt,{r,c}};
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while(!pq.empty()){
            int wt = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n - 1 and c == m - 1) return dis[r][c];
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m){
                    int ne = max(wt,abs(v[r][c] - v[nr][nc]));
                    if(dis[nr][nc] > ne){
                        dis[nr][nc] = ne;
                        pq.push({ne, {nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};