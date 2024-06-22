class Solution {
public:
    int solve(vector<int>&nums,int ind,int prevind,vector<vector<int>>dp){
        int n=nums.size();
        if(dp[ind][prevind+1]!=-1)return dp[ind][prevind+1];
        if(ind==n)return 0;
        int npick=solve(nums,ind+1,prevind,dp);
        int pick=0;
        if(prevind==-1 || nums[prevind]<nums[ind]){
            pick=1+solve(nums,ind+1,ind,dp);
        }
        return dp[ind][prevind+1]=max(pick,npick);
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        int maxBitonic = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxBitonic = max(maxBitonic, lis[i] + lds[i] - 1);
            }
        }

        return n - maxBitonic;
    }
};
