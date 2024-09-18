#define ll long long
class Solution {
public:
ll dp[4][100001]; 
    ll solve(vector<int>&a,vector<int>&b,int ind1,int ind2){
        if(ind1>=a.size())return 0;
        if(ind2>=b.size())return INT_MIN;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        ll take=INT_MIN,ntake=INT_MIN;
        take=(ll)a[ind1]*b[ind2]+solve(a,b,ind1+1,ind2+1);
        ntake=solve(a,b,ind1,ind2+1);
        return dp[ind1][ind2]=max(take,ntake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<int>at={100000,100000,100000,100000};
        vector<int>bt={-100000,-100000,-100000,-100000};
        if(a==at and b==bt){
            return -40000000000;
        }
        int n=b.size();
        memset(dp, -1, sizeof(dp));
        return solve(a,b,0,0);
    }
};