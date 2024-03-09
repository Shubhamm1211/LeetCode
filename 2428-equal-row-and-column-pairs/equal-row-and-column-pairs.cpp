class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int n=grid.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
            mp[temp]++;
        }
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            if(mp.find(temp)!=mp.end()){
                ans+=mp[temp];
            }
        }
        return ans;
        
    }
};