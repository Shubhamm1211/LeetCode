#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& v) {
        sort(begin(v),end(v));
        priority_queue<ll,vector<ll>,greater<ll>>pq1;
        for(ll i = 0; i < n; i++){
            pq1.push(i);
        }
        vector<ll> cnt(n,0);
        priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq2; //{end,roomNum}
        for(ll i = 0; i < v.size(); i++){
            ll start = v[i][0];
            ll end = v[i][1];
            while(!pq2.empty() and start >= pq2.top().first){
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            if(!pq1.empty()){
                ll num = pq1.top();
                pq1.pop();
                pq2.push({end,num});
                cnt[num]++;
            }
            else{
                ll num = pq2.top().second;
                ll newstart = pq2.top().first;
                pq2.pop();
                ll newend = newstart + (end - start);
                pq2.push({newend,num});
                cnt[num]++;
            }
        }
        ll maxi = INT_MIN;
        ll ans = -1;
        for(ll i = 0; i < cnt.size(); i++){
            if(cnt[i] > maxi){
                maxi = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};
