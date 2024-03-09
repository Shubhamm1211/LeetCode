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
            int temp=INT_MIN;
            for(int j=0;j<row;j++){
                temp=max(temp,grid[j][i]);
            }
            ans=ans+temp;
        }
        return ans;
    }
};