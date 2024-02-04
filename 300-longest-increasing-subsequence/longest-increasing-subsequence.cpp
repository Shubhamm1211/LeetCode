class Solution {
public:
    int solve(vector<int>&nums,int ind,int prevind,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n)return 0;
        if(dp[ind][prevind+1]!=-1)return dp[ind][prevind+1];
        int nottake=solve(nums,ind+1,prevind,dp);
        int take=0;
        if(prevind==-1||nums[ind]>nums[prevind]){
            take=1+solve(nums,ind+1,ind,dp);
        }
        return dp[ind][prevind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,0,-1,dp);
    }
};