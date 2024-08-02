class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> cir(nums.begin(), nums.end());
        cir.insert(cir.end(), nums.begin(), nums.end());

        int oneCount = count(nums.begin(), nums.end(), 1);
        int l = 0, r = 0, zeroCount = 0, minSwaps = INT_MAX;

        while (r < 2 * n) {
            if (r - l < oneCount) {
                if (cir[r] == 0) zeroCount++;
                r++;
            } else {
                minSwaps = min(minSwaps, zeroCount);
                if (cir[l] == 0) zeroCount--;
                l++;
            }
        }
        return minSwaps;
    }
};
