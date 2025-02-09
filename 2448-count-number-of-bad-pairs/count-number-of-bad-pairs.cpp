#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        vector <ll> temp;
        unordered_map<ll,ll> mp;
        for(ll i = 0; i < n; i++){
            temp.push_back(nums[i] - i);
            mp[temp[i]]++;
        }
        ll ans = (n * (n - 1)) / 2;
        ll sub = 0;
        for(auto x : mp){
            if(x.second > 1){
                sub += (x.second * (x.second - 1)) / 2;
            }
        }
        return ans - sub;
    }
};