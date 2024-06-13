class Solution {
public:
    int solve(string w1,string w2,int i,int j,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j])return solve(w1,w2,i-1,j-1,dp);
        else{
            int a=solve(w1,w2,i-1,j,dp);
            int b=solve(w1,w2,i-1,j-1,dp);
            int c=solve(w1,w2,i,j-1,dp);
            return dp[i][j]=1+min(a,min(b,c));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};