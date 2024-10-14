#define ll long long 
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        priority_queue <ll> pq (nums.begin(),nums.end());
        while(k > 0){
            if(!pq.empty()){
                ll t = pq.top();
                pq.pop();
                ans += t;
                pq.push(ceil(t / 3.0));
            }
            k--;
        }
        return ans;
    }
};