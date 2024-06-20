class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        vector<int>ans(2,-1);
        int l=lower_bound(nums.begin(),nums.end(),tar)-nums.begin();
        int u=upper_bound(nums.begin(),nums.end(),tar)-nums.begin()-1;
        if(l>=0 and l<nums.size() and nums[l]==tar)ans[0]=l;
        if(u>=0 and u<nums.size() and nums[u]==tar)ans[1]=u;
        return ans;
    }
};