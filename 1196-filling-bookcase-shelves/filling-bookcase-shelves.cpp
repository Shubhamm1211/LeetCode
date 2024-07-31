class Solution {
public:
    int solve(vector<vector<int>>& books,int t,int ind,int currw,int currh,vector<vector<int>>&dp){
        int n=books.size();
        if(ind==n)return currh;
        if(dp[ind][currw]!=-1)return dp[ind][currw];
        int npick=currh+solve(books,t,ind+1,books[ind][0],books[ind][1],dp);
        int pick=INT_MAX;
        if(currw+books[ind][0]<=t){
            pick=solve(books,t,ind+1,currw+books[ind][0],max(currh,books[ind][1]),dp);
        }
        return dp[ind][currw]=min(pick,npick);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>>dp(n+1,vector<int>(shelfWidth+1,-1));
        return solve(books,shelfWidth,0,0,0,dp);
    }
};