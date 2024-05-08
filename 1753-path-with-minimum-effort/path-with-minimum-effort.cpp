class Solution {
public:
    int minimumEffortPath(vector<vector<int>>&h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        while(!pq.empty()){
            auto top=pq.top();
            int d=top.first;
            int row=top.second.first;
            int col=top.second.second;
            pq.pop();
            if(row==n-1 && col==m-1)return d;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int ne=max(abs(h[nrow][ncol]-h[row][col]),d);
                    if(ne<dis[nrow][ncol]){
                        dis[nrow][ncol]=ne;
                        pq.push({ne,{nrow,ncol}});
                    }
                }
            }
        }
        
        return 0;

    }
};