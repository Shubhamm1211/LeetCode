class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k,0);
        map<int,vector<int>>mp;
        for(auto vect:logs){
            mp[vect[0]].push_back(vect[1]);
        }
        for(auto it:mp){
            set<int>s;
            for(auto ele:it.second){
                s.insert(ele);
            }
            ans[s.size()-1]++;
        }
        return ans;
    }
};