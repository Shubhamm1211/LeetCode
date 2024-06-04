class Solution {
public:
    int solve(vector<vector<int>>& pairs,int indrow,vector<int>&dp){
        if(indrow==0)return 1;
        if(dp[indrow]!=-1)return dp[indrow];
        int pick=1;
        for (int i=0;i<indrow;i++) {
            if (pairs[i][1]<pairs[indrow][0]) {
                pick=max(pick,1+solve(pairs,i,dp));
            }
        }
        int notpick=0+solve(pairs,indrow-1,dp);
        return dp[indrow]=max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int>dp(n+1,-1);
        return solve(pairs,n-1,dp);
    }
};