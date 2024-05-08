class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int dr[8]={-1,-1,0,1,1,1,0,-1};
        int dc[8]={0,1,1,1,0,-1,-1,-1};
        int n=grid.size();
        pq.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        while(!pq.empty()){
            auto top=pq.top();
            int dis=top.first;
            int row=top.second.first;
            int col=top.second.second;
            pq.pop();
            if(row==n-1 && col==n-1)return dis;
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0  && ncol<n && grid[nrow][ncol]==0
                && dist[nrow][ncol]>1+dis){
                    dist[nrow][ncol]=1+dis;
                    pq.push({1+dis,{nrow,ncol}});
                }
            }


        }
        return -1;
    }
};