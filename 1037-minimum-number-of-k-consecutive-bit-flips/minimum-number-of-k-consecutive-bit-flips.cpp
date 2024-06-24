class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            if ((dq.size() % 2 == nums[i])) {
                if (i + k > n) {
                    return -1;  
                }
                dq.push_back(i);
                ans++;
            }
        }
        
        return ans;
    }
};
