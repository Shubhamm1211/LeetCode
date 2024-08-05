class Solution {
public:
    int solve(int ind,string s,vector<int>&dp){
        if(ind==s.size()){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int ans=solve(ind+1,s,dp);
        if(ind+1<s.size() and (s[ind]=='1' || (s[ind]=='2' and s[ind+1]<='6'))){
            ans=ans+solve(ind+2,s,dp);
        }
        return dp[ind]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
};