class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int k=col;
        for(int i=0;i<row;i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int ans=0;
        for(int i=0;i<col;i++){
            priority_queue<int>pq;
            for(int j=0;j<row;j++){
                pq.push(grid[j][i]);
            }
            ans=ans+pq.top();
        }
        return ans;
    }
};