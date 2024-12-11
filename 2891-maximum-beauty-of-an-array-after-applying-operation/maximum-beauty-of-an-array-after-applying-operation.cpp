class Solution {
public:
        int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ind = 0;
        int n = nums.size();
        int j = 0;
        for (j = 0; j < n; j++){
            if (nums[j] - nums[ind] > 2 * k){
                ind++;
            }
        }
        return j - ind;
    }
};