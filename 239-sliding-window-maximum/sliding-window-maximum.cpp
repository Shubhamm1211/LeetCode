class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            pq.push({arr[i],i});
            while(!pq.empty() and pq.top().second <= i - k){
                pq.pop();
            }
            if(i >= k-1){
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};