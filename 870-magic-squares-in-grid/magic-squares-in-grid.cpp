class Solution {
public:
    bool magic(int sr,int sc,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(sc+3>m || sr+3>n){
            return false;
        }
        bool checkrows=true;
        bool diff=true;
        int sum=0;
        vector<int>vis(10,0);
        for(int i=0;i<3;i++){
            int rowsum=0;
            for(int j=0;j<3;j++){
                int val= grid[i+sr][j+sc];
                if (val < 1 || val > 9 || vis[val] == 1) {
                    return false;
                }
                vis[val] = 1;
                rowsum += val;
            }
            if(i==0){
                sum=rowsum;
            }
            else{
                if(rowsum!=sum)checkrows=false;
            }
        }
        bool checkcols=true;
        int sum2=0;
        for(int j=0;j<3;j++){
            int colsum=0;
            for(int i=0;i<3;i++){
                colsum+=grid[i+sr][j+sc];
            }
            if(j==0){
                sum2=colsum;
            }
            else{
                if(colsum!=sum2)checkcols=false;
            }
        }
        bool checkdig1=true,checkdig2=true;
        int d1=grid[sr][sc]+grid[sr+1][sc+1]+grid[sr+2][sc+2];
        int d2=grid[sr+2][sc]+grid[sr+1][sc+1]+grid[sr][sc+2];
        if(d1!=sum)return false;
        if(d2!=sum)return false;
        if(checkrows and checkcols and diff) return true;
        else return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0 ; j < m ; j++){
                if(magic(i,j,grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

