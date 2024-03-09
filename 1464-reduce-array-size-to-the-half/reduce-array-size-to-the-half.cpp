using pii=pair<int,int>;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }
        priority_queue<pii>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int half=arr.size()/2;
        int val=pq.top().first;
        pq.pop();
        int ans=1;
        while(val<half){
            if(!pq.empty()){
                val=val+pq.top().first;
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};