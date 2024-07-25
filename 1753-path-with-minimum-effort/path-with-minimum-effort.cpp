class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==n-1 and c==m-1)return dist[r][c];
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];                
                if(nr>=0 and nr<n and nc>=0 and nc<m ){
                    int ne=max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(ne<dist[nr][nc]){
                        dist[nr][nc]=ne;
                        pq.push({ne,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};