class Solution {
public:
    long long solve(int ind,int take,vector<int>&nums,vector<vector<long long>>&dp){
        if(ind==nums.size())return 0;
        if(dp[ind][take]!=-1)return dp[ind][take];
        long long ans;
        if(take){
            ans=max(nums[ind]+solve(ind+1,0,nums,dp),solve(ind+1,1,nums,dp));
        }
        else{
            ans=max(-nums[ind]+solve(ind+1,1,nums,dp),solve(ind+1,0,nums,dp));
        }
        return dp[ind][take]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(0,1,nums,dp);
    }
};