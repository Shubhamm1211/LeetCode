class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[sr][sc]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and !vis[nr][nc]){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int calcislands(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int islands=calcislands(grid);
        int n=grid.size();
        int m=grid[0].size();
        if(islands>1 or islands==0)return 0;
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        int t=calcislands(grid);
                        if(t>1 or t==0)return 1;
                        else grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};