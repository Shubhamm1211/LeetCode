class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        vector<long long> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i];
        }
        for (int target : q) {
            long long pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            long long ls = ps[pos];
            long long rs = ps[n] - ps[pos];
            long long lo = target * pos - ls;
            long long ro = rs - target * (n - pos);
            ans.push_back(lo + ro);
        }
        
        return ans;
    }
};
