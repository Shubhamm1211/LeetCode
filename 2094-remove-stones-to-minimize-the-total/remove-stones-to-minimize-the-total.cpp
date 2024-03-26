class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int>pq;
        for(auto e:p){
            pq.push(e);
        }
        while(k--){
            double t=pq.top();
            pq.pop();
            pq.push(ceil(t/2));
        }
        int ans=0;
        while(!pq.empty()){
            int x=pq.top();
            ans=ans+x;
            pq.pop();
        }
        return ans;
    }
};