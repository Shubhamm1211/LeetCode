class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int x : nums) {
            int curr = 0;
            long long ele = x;
            while (st.find((int)ele) != st.end()) {
                curr++;
                if (ele * ele > 1e5) break;
                ele *= ele;
            }
            ans = max(ans, curr);
        }
        return ans < 2 ? -1 : ans;
        if(ans < 2) return -1;
        else return ans;
    }
};