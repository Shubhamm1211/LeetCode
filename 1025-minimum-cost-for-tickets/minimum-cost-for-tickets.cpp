class Solution {
public:
    // bool find(int n,vector<int>&days){
    //     for(auto x:days){
    //         if(n==x)return true;
    //     }
    //     return false;
    // }
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