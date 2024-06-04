class Solution {
public:
    // bool find(int n,vector<int>&days){
    //     for(auto x:days){
    //         if(n==x)return true;
    //     }
    //     return false;
    // }


    // Memoization below
    int helper(const vector<int>& days, const vector<int>& costs, const unordered_set<int>& st, int day, vector<int>& memo, int maxd) {
        if (day > maxd) {
            return 0;
        }
        if (memo[day] != -1) {
            return memo[day];
        }

        if (st.find(day) == st.end()) {
            memo[day] = helper(days, costs, st, day + 1, memo, maxd);
        } else {
            int cost1 = costs[0] + helper(days, costs, st, day + 1, memo, maxd);
            int cost7 = costs[1] + helper(days, costs, st, day + 7, memo, maxd);
            int cost30 = costs[2] + helper(days, costs, st, day + 30, memo, maxd);
            memo[day] = min({cost1, cost7, cost30});
        }

        return memo[day];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxd=days[days.size()-1];
        int n=days.size();
        unordered_set<int>st(days.begin(), days.end());
        vector<int>dp(maxd+1,0);
        for(int i=1;i<=maxd;i++){
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
            }
            else{
                int a=costs[0]+dp[i-1];
                int b=costs[1],c=costs[2];
                if(i-7>=0)b=b+dp[i-7];
                if(i-30>=0)c=c+dp[i-30];
                dp[i]=min(a,min(b,c));
            }
        }
        return dp[maxd];
    }
};