class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int oddcnt = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if(mp[s[i]]%2==1)oddcnt++;
            else oddcnt--;
        }
        

        if (oddcnt > 1) return s.size() - oddcnt + 1;
        return s.size();
    }
};
