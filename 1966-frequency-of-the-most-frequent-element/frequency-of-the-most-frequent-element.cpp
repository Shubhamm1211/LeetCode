#define ll long long 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        ll i = 0, j = 0;
        ll sum = 0;
        ll ans = 1;
        while(j < n){
            sum += nums[j];
            while(nums[j] * (j - i + 1) - sum > k){
                sum -= nums[i];
                i++;
            }
            ans = max(ans,j - i + 1);
            j++;
        }
        return ans;
    }
};