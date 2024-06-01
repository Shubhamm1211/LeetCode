class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),l=0,r=0,sum=0;
        int mini=INT_MAX;
        while(r<n){
            sum=sum+nums[r];
            while(sum>=target){
                mini=min(mini,r-l+1);
                sum=sum-nums[l];
                l++;
            }
            r++;
        }
        if(mini==INT_MAX)return 0;
        return mini;
    }
};