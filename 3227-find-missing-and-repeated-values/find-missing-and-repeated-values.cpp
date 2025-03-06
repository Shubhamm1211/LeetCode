class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector <int> ans;
        int n = grid.size();
        int sum = 0;
        map <int,int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mp.find(grid[i][j]) != mp.end()){
                    ans.push_back(grid[i][j]);
                }
                else{
                    mp[grid[i][j]]++;
                    sum += grid[i][j];
                }
            }
        }
        n = n * n;

        ans.push_back((n * (n + 1)) / 2 - sum);
        return ans;
    }
};