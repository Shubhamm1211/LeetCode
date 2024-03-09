class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(!pq.empty() || pq.size()>1){
            if(pq.empty()||pq.size()==1)break;
            int n1=pq.top();
            pq.pop();
            int n2=pq.top();
            pq.pop();
            if(n1-n2>0){
                pq.push(n1-n2);
            }
        }
        if(!pq.empty())return pq.top();
        else return 0;
    }
};