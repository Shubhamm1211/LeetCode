class Solution {
public:
    // bool solve(int ind,vector<int>&v,int tar,vector<vector<int>>&dp){
    //     if(tar==0)return true;
    //     if(ind==0)return v[ind]==tar;
    //     if(dp[ind][tar]!=-1)return dp[ind][tar];
    //     bool npick=solve(ind-1,v,tar,dp);
    //     bool pick=false;
    //     if(tar>=v[ind]){
    //         pick=solve(ind-1,v,tar-v[ind],dp);
    //     }
    //     return dp[ind][tar]=pick||npick;
    // }
    // bool check(vector<int>&v,int tar){
    //     int n=v.size();
    //     vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    //     return solve(n-1,v,tar,dp);
    // }
    // int getMaximumConsecutive(vector<int>& coins) {
    //     sort(coins.begin(),coins.end());
    //     int maxi=accumulate(coins.begin(),coins.end(),0);
    //     int ans=0;
    //     for(int i=1;i<=maxi;i++){
    //         if(check(coins,i))ans++;
    //         else break;
    //     }
    //     return ans+1;
    // }
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int ans=0;
        for(auto c:coins){
            if(c>ans+1)break;
            else ans=ans+c;
        }
        return ans+1;
    }
};