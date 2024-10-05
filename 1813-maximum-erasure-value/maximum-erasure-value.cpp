class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = 0;
        map<int,int>mp;
        int curr = 0;
        while(j < n){
            mp[nums[j]]++;
            curr += nums[j];
            while(mp[nums[j]] > 1){
                curr -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size() == j - i + 1) maxi = max(maxi,curr);
            j++;
        }
        return maxi;
    }
};