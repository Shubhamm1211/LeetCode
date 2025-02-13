#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <ll, vector <ll> , greater <ll> > pq(begin(nums), end(nums));
        ll ans = 0;
        while(!pq.empty() and pq.top() < k){
            if(pq.size() >= 2){
                ll t1 = pq.top();
                pq.pop();
                ll t2 = pq.top();
                pq.pop();
                pq.push(min(t1,t2) * 2 + max(t1,t2));
                ans++;
            }
        }
        return ans;
    }
};