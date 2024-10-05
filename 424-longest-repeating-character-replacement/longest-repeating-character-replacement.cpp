class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map <char,int> mp;
        int i = 0, j = 0;
        int maxi = 0;
        int cnt = 0;
        while(j < n){
            char c = s[j];
            mp[c]++ ; 
            cnt = max(cnt,mp[c]);
            if(j - i + 1 - cnt > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            } 
            else maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};