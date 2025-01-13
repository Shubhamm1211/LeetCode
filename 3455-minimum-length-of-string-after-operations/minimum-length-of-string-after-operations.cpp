class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3) return s.size();
        map <char,int> mp;
        for(auto &x : s){
            mp[x]++;
        }
        int ans = 0;
        for(auto &x : mp){
            int freq = x.second;
            if(freq & 1){
                ans += 1;
            }
            else ans += 2;
        }
        return ans;
    }
};
