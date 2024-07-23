bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first)return a.second>b.second;
        else return a.first<b.first;
    }
class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>v; //{freq,elem}
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            while(v[i].first>0){
            ans.push_back(v[i].second);
            v[i].first--;
            }
        }
        return ans;
    }
};