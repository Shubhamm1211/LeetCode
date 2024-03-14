class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        mp[0] = 1;
        for(int num : nums) {
            sum += num;
            if(mp.find(sum - goal) != mp.end())
                ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};