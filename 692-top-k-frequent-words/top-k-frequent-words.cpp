    bool check(pair<string,int>&p1,pair<string,int>&p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
    }
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>>v;
        for(auto x:mp){
            v.push_back({x.first,x.second});
        }
        vector<string>ans;
        sort(v.begin(),v.end(),check);
        for(auto x:v){
            if(k>0)ans.push_back(x.first);
            k--;
        }
        return ans;
    }
};