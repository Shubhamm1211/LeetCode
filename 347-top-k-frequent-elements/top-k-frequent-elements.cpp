using pii=pair<int,int>;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii,vector<pii>,greater<pii>>p;
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            p.push({x.second,x.first});
            if(p.size()>k)p.pop();
        }
        vector<int>ans;
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};