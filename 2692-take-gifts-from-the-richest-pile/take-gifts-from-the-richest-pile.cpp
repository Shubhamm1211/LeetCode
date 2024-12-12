#define ll long long
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> pq(begin(gifts),end(gifts));
        for(int i = 0; i < k; i++){
            int top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top * 1.0)));
        }
        ll sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};