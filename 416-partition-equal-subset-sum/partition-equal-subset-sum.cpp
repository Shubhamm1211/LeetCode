class Solution {
public:
    bool solve(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return nums[ind]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notpick=solve(ind-1,target,nums,dp);
        bool pick=false;
        if(nums[ind]<=target){
            pick=solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=(pick||notpick);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1)return false;
        else{
            int target=sum/2;
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return solve(n-1,target,nums,dp);
        }
    }
};