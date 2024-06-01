class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        int l = 0, r = 0;
        map<char, int> mp1, mp2;
        for (auto c : p) {
            mp2[c]++;
        }
        vector<int> ans;
        while (r < n1) {
            mp1[s[r]]++;
            if (r - l + 1 == n2) {
                if (mp1 == mp2) {
                    ans.push_back(l);
                }
                mp1[s[l]]--;
                if (mp1[s[l]] == 0)
                    mp1.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
