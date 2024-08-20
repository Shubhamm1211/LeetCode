class Solution {
public:
    int n;
    int dp[2][101][101]; 
    int solve(vector<int>& piles, int person, int ind, int m) {
        if(ind>=n)return 0;
        if(dp[person][ind][m]!=-1)return dp[person][ind][m];
        int res;
        if(person==1)res=-1;
        else res=INT_MAX;
        int stones=0;
        for(int x=1;x<=min(2*m,n-ind);x++){
            stones+=piles[ind+x-1];
            if(person==1){
                res=max(res,stones+solve(piles,0,ind+x,max(x,m)));
            }
            else res=min(res,solve(piles,1,ind+x,max(x,m)));
        }
        return dp[person][ind][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, 1, 0, 1);
    }
};


