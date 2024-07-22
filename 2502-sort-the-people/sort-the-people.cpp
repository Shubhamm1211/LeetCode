class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        vector<pair<int,string>>v;
        int n=names.size();
        for(int i=0;i<n;i++){
            v.push_back({h[i],names[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,string>>());
        vector<string>ans;
        for(int i=0;i<n;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};