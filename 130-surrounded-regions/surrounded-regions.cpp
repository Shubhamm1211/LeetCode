class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board){
        int n=vis.size();
        int m=vis[0].size();
        vis[r][c]=1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and board[nr][nc]=='O'){
                vis[nr][nc]=1;
                dfs(nr,nc,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] and board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] and board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] and board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i] and board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};