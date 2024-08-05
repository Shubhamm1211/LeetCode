class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<int>&dp){
        int n=nums.size();
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int currsum=nums[ind];
        int currval=nums[ind];
        int temp=ind+1;
        while(temp<n and nums[temp]==currval){
            currsum+=nums[temp];
            temp++;
        }
        while(temp<n and nums[temp]==currval+1){
            temp++;
        }
        return dp[ind]=max(currsum+solve(nums,temp,dp),solve(nums,ind+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};