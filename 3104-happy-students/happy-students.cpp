class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(i+1 > nums[i] and i+1 < nums[i+1]) cnt++;
        }
        if(nums[0] != 0) cnt++;
        return cnt;
    }
};
