class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }
        while(k--){
            if(!pq.empty()){
                int mini = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                pq.push({mini * mul,ind});
            }
        }
        vector <int> ans(n);
        while(!pq.empty()){
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};