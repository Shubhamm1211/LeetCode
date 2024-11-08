class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector <int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pref[i] = pref[i - 1] ^ nums[i];
        }
        int mask = (1 << maximumBit) - 1;
        vector <int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = (pref[i] ^ mask);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};