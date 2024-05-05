class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] and grid[nr][nc]==1){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,vis,grid);
            }
            if(!vis[n-1][i] and grid[n-1][i]==1){
                dfs(n-1,i,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] and grid[i][0]){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] and grid[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]==0)ans++;
            }
        }
        return ans;
    }
};