class Solution {
public:
    int solve(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(ind==0){
            if(target==0 && nums[0]==0)return 2;
            if(target==0 || nums[ind]==target)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
            int notpick=solve(ind-1,nums,target,dp);
            int pick=0;
            if(nums[ind]<=target){
                pick=solve(ind-1,nums,target-nums[ind],dp);
            }
            return dp[ind][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum=0;
        for(auto x:nums) totsum+=x;
        int s2=(totsum-target)/2;
        if(totsum-target<0 || (totsum-target)%2==1 )return 0;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return solve(n-1,nums,s2,dp);
    }
};