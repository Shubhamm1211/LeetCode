class Solution {
public:
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=1+solve(ind1-1,ind2-1,s1,s2,dp);
        }
        else{
            return dp[ind1][ind2]=max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        int ind1=s.size();
        int ind2=s2.size();
        vector<vector<int>>dp(ind1,vector<int>(ind1+1,-1));
        return solve(ind1-1,ind2-1,s,s2,dp);
    }
};