class Solution {
public:
    void solve(vector<int>nums,int i,int n,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int j=i;j<n;j++){
            ds.push_back(nums[j]);
            solve(nums,j+1,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        int n=nums.size();
        vector<int>ds;
        solve(nums,0,n,ds,ans);
        return ans;
    }
};