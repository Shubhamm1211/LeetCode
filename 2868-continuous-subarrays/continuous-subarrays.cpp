#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll n = nums.size();
        ll i = 0, j = 0;
        map<ll,ll> mp;
        ll ans = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.rbegin() -> first - mp.begin() -> first > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};