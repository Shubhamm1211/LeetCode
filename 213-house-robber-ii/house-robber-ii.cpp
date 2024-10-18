class Solution {
public:
    int solve(vector <int> &v, int ind, vector <int> &dp){
        if(ind == 0){
            return v[ind];
        }

        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = v[ind] + solve(v, ind - 2, dp);
        int notpick = solve(v,ind - 1, dp);
        
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector <int> v1(nums.begin(),nums.end() - 1);
        vector <int> v2(nums.begin() + 1, nums.end());

        int n1 = v1.size(), n2 = v2.size();
        vector <int> dp1(n1,-1), dp2(n2,-1);
        int a1 = solve(v1, n1 - 1, dp1);
        int a2 = solve(v2, n2 - 1, dp2);
        return max(a1,a2);
    }
};