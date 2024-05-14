class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        int maxi=0;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nc>=0 && nc<m && nr>=0 && nr<n && !vis[nr][nc] && grid[nr][nc]){
                maxi=max(maxi,grid[nr][nc]+dfs(nr,nc,vis,grid));
            }
        }
        vis[i][j]=0;
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]!=0)
                maxi=max(maxi,grid[i][j]+dfs(i,j,vis,grid));
            }
        }
        return maxi;
    }
};