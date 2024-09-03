class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        priority_queue<int>pq;
        vector<int>ans;
        for(int i=0;i<q.size();i++){
            int dist=abs(q[i][0])+abs(q[i][1]);
            pq.push(dist);
            if(pq.size()<k){
                ans.push_back(-1);
            }
            else{
                if(pq.size()>k){
                    pq.pop();
                }
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};