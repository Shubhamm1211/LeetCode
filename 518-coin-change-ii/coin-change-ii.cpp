class Solution {
public:
    
    int solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(ind==0){
            if(target%arr[0]==0)return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notpick=solve(ind-1,target,arr,dp);
        int pick=0;
        if(arr[ind]<=target){
            pick=solve(ind,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};