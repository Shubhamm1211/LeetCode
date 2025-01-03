#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll n = nums.size();
        vector <ll> pre(n);
        pre[0] = nums[0];
        for(ll i = 1; i < n; i++){
            pre[i] = pre[i - 1] + nums[i];
        }
        ll ans = 0;
        for(ll i = 0; i < n - 1; i++){
            ll curr = pre[i];
            if(pre.back() - curr <= curr){
                ans++;
            }
        }
        return ans;
    }
};