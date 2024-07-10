class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        int org=image[sr][sc];
        if(org==color)return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==org){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};