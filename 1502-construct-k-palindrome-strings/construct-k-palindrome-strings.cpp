class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k == n){
            return true;
        }
        if(n < k){
            return false;
        }
        int cnt = 0;
        map <char,int> mp;
        for(auto x : s) mp[x]++;
        for(auto x : mp){
            if((x.second & 1)) cnt++;
        }
        if(cnt > k) return false;
        return true;
    }
};