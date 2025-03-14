#define ll long long
class Solution {
public:
    bool check(vector<int> &nums, ll k, ll mid) {
        ll cnt = 0;
        for(ll i = 0; i < nums.size(); i++) {
            cnt += nums[i] / mid;
        }
        if(cnt >= k) return true;
        return false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        ll sum = accumulate(begin(nums), end(nums), 0LL);
        if(sum < k) return 0;
        ll low = 1, high = sum / k;
        ll ans = 0;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check(nums, k, mid)) {
                ans = mid; 
                low = mid + 1; 
            } 
            else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};
