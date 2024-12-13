#define ll long long
class Solution {
public:
    long long findScore(vector<int>& nums) {
        ll n = nums.size();
        priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        for(ll i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        ll curr1 = - 1, curr2 = -1;
        ll ans = 0;
        vector <ll> vis(n,0); 
        while(!pq.empty()){
            ll temp = pq.top().first;
            ll ind  = pq.top().second;
            if(!vis[ind]){
                ans += temp;
                vis[ind] = 1;
                if(ind > 0){
                    vis[ind - 1] = 1;
                }
                if(ind < n - 1){
                    vis[ind + 1] = 1;
                }
            }
            pq.pop();
        }
        return ans;
    }
};