class Solution {
public:
    void solve(int i,vector<int>nums,vector<vector<int>>&ans,
    vector<int>&ds,int k,int n){
        if(i==nums.size()){
        if(n==0 && ds.size()==k){
            ans.push_back(ds);  
        }
        return;
        }
        if(nums[i]<=n){
            ds.push_back(nums[i]);
            solve(i+1,nums,ans,ds,k,n-nums[i]);
            ds.pop_back();
        }
        solve(i+1,nums,ans,ds,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums,ans,ds,k,n);
        return ans;
    }
};