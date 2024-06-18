class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        priority_queue<int>pq(s.begin(),s.end());
        int curr=0,ans=0;
        while(!pq.empty() and pq.top()+curr>0){
            curr=curr+pq.top();
            pq.pop();
            ans=ans+curr;
        }
        return ans;
    }
};