class Solution {
public:
        int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for (auto i : answers) {
            mp[i]++;
        }
        int ans=0;
        for (auto x:mp) {
        ans=ans+(x.second+x.first)/(x.first+1)*(x.first+1);
        }
        return ans;
    }
};