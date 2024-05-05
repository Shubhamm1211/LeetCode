class Solution {
private:
void dfs(int r,int c,vector<vector<char>>&b,vector<vector<int>>&vis){
    vis[r][c]=1;
    int n=vis.size();
    int m=vis[0].size();
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && b[nr][nc]=='O'){
            dfs(nr,nc,b,vis);
        }
    }
}
public:
    void solve(vector<vector<char>>&b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] and b[0][i]=='O'){
                dfs(0,i,b,vis);
            }
            if(!vis[n-1][i] and b[n-1][i]=='O'){
                dfs(n-1,i,b,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] and b[i][0]=='O'){
                dfs(i,0,b,vis);
            }
            if(!vis[i][m-1] and b[i][m-1]=='O'){
                dfs(i,m-1,b,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and b[i][j]=='O'){
                    b[i][j]='X';
                }
            }
        }
    }
};