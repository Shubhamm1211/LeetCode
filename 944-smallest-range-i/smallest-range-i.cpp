class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int diff=maxi-mini;
        if(diff-2*k<=0)return 0;
        else return diff-2*k;
    }
};