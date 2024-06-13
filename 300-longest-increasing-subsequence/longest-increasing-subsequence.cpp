class Solution {
public:
    int solve(vector<int>&nums,int ind,int prev,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int npick=solve(nums,ind+1,prev,n,dp);
        int pick=0;
        if(prev==-1||nums[prev]<nums[ind]){ 
            pick=1+solve(nums,ind+1,ind,n,dp);
        }
        return dp[ind][prev+1]=max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,0,-1,n,dp);
    }
};