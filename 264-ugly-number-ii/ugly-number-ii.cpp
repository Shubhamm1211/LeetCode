class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++){
            int twom=dp[p1]*2;
            int threem=dp[p2]*3;
            int fivem=dp[p3]*5;
            dp[i]=min({twom,threem,fivem});
            if(dp[i]==twom)p1++;
            if(dp[i]==threem)p2++;
            if(dp[i]==fivem)p3++;
        }
        return dp[n-1];
    }
};