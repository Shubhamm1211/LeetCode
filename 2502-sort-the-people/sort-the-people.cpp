bool comp(pair<string,int>&a,pair<string,int>&b){
    return b.second<a.second;
}
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        vector<pair<string,int>>p;
        for(int i=0;i<names.size();i++){
            p.push_back({names[i],h[i]});
        }
        sort(p.begin(),p.end(),comp);
        vector<string>ans;
        for(auto it:p){
            ans.push_back(it.first);
        }
        return ans;
    }
};