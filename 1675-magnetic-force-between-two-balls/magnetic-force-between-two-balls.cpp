#define ll long long
class Solution {
public:
    ll n;
    bool solve(vector <int> &arr, int k, int mid){
        int cnt = 1;
        int curr = arr[0];
        for(ll i = 1; i < n; i++){
            if(arr[i] - curr >= mid){
                cnt++;
                curr = arr[i];
            }
        }
        return cnt >= k;
    }
    int maxDistance(vector<int>& arr, int m) {
        n = arr.size();
        ll low = 1;
        ll high = *max_element(begin(arr), end(arr));
        ll ans = -1;
        sort(begin(arr), end(arr));
        while(low <= high){
            ll mid = high - ((high - low) / 2);
            if(solve(arr,m,mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};