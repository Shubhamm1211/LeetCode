class Solution {
public:
    int solve(int ind , int end , vector<int>&nums,vector<int>&dp){
        if(ind == end) return 0 ;
        if( dp[ind]!=-1 ) return dp[ind];
        int mini = INT_MAX;
        for(int i = 1 ; i <= nums[ind] ; i++) {
            if(ind+i <= end){
            int jump = solve(ind+i, end, nums, dp);
            if( jump != INT_MAX ) {
            mini=min(mini,jump+1);
            }
            }
        }
        return dp[ind]=mini;

    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0, n-1, nums, dp);
        if(ans == INT_MAX) return -1;
        return ans ;
    }
};