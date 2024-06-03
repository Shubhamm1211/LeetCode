class Solution {
public:
    int solve(vector<int>nums,int ind,vector<int>&dp){
        if(ind==0)return nums[0];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+solve(nums,ind-2,dp);
        int notpick=solve(nums,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        int n1=nums1.size();
        vector<int>dp1(n1,-1),dp2(n1,-1);
        int s1=solve(nums1,n1-1,dp1);
        int n2=nums2.size();
        int s2=solve(nums2,n2-1,dp2);
        return max(s1,s2);
    }
};