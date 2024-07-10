class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int RowSize=mat.size();
        int ColSize=mat[0].size();
        vector<vector<int>>dis(RowSize,vector<int>(ColSize,0));
        vector<vector<int>>vis(RowSize,vector<int>(ColSize,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<RowSize;i++){
            for(int j=0;j<ColSize;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dis[row][col]=step;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 and nr<RowSize and nc>=0 and nc<ColSize and !vis[nr][nc]){
                    q.push({{nr,nc},step+1});
                    vis[nr][nc]=1;
                }
            }
            
        }
        
        return dis;


    }
};