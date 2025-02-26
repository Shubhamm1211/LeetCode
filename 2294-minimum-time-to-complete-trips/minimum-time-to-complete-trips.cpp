#define ll long long
class Solution {
public:
    ll n;
    bool solve(vector <int> &arr, int k, ll mid){
        ll tot = 0;
        for(ll i = 0; i < n; i++){
            tot += mid / arr[i];
        }
        return tot >= k;
    }
    long long minimumTime(vector<int>& arr, int k) {
        n = arr.size();
        ll low = 1;
        ll high = 1e14;
        ll ans = -1;
        while(low <= high){
            ll mid = high - ((high - low) / 2);
            if(solve(arr,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};