class Solution {
public:
    int solve(string &s,string &t,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=1+solve(s,t,ind1-1,ind2-1,dp);
        }
            return dp[ind1][ind2]=max(solve(s,t,ind1-1,ind2,dp),solve(s,t,ind1,ind2-1,dp));
        
    }
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=solve(s,t,n-1,m-1,dp);
        if(ans==s.size())return true;
        else return false;
    }
};