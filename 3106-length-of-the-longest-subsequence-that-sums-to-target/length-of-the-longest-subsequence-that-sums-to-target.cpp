class Solution {
public:
    int solve(vector<int>&nums,int ind,int target,vector<vector<int>>&dp){
        if(target==0)return 0;
        if(ind==nums.size())return INT_MIN;
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nottake=solve(nums,ind+1,target,dp);
        int take=INT_MIN;
        if(target-nums[ind]>=0){
            take=1+solve(nums,ind+1,target-nums[ind],dp);
        }
        return dp[ind][target]=max(nottake,take);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=solve(nums,0,target,dp);
        if(ans>0)
        return ans;
        else return -1;
    }
};