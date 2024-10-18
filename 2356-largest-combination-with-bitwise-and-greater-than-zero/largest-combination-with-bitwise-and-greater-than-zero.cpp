class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int> bits(32);  
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        int ans = *max_element(begin(bits), end(bits));
        return ans;
    }
};
