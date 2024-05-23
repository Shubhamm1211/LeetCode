class Solution {
public:
    void solve(vector<int>nums,int i,int n,vector<int>&ds,vector<vector<int>>&ans){
        if(i==nums.size()){
        ans.push_back(ds);
        return;
        }
        ds.push_back(nums[i]);
        solve(nums,i+1,n,ds,ans);
        ds.pop_back();
        solve(nums, i + 1,n, ds, ans);
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