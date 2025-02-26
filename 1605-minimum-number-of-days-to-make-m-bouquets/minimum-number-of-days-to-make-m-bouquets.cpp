#define ll long long
class Solution {
public:
    ll solve(vector <int> &arr, int m, int k, int mid){
        ll n = arr.size();
        ll cnt = 0, ans = 0;
        for(ll i = 0; i < n; i++){
            if(arr[i] <=  mid){
                cnt++;
            }
            else cnt = 0;
            if(cnt == k){
                ans++;
                cnt = 0;
            }
        }
        return ans >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        ll n = arr.size();
        ll tot = (ll)m * k;
        if(n < tot) return -1;
        ll low = 1;
        ll high = *max_element(begin(arr), end(arr));
        ll ans = -1;
        while(low <= high){
            ll mid = high - ((high - low) / 2);
            if(solve(arr,m,k,mid)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};