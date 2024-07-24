class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        int dr[8]={-1,-1,0,1,1,1,0,-1};
        int dc[8]={0,1,1,1,0,-1,-1,-1};
        while(!pq.empty()){
            auto node=pq.top();
            int len=node.first;
            int row=node.second.first;
            int col=node.second.second;
            pq.pop();
            if(row==n-1 and col==n-1)return len;
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and 
                dist[nrow][ncol]>1+len){
                    dist[nrow][ncol]=1+len;
                    pq.push({len+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};