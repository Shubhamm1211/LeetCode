class Solution {
public:
    bool canChange(string s1, string s2) {
        int n = s1.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            while (i < n && s1[i] == '_') {
                i++;
            }
            while (j < n && s2[j] == '_') {
                j++;
            }
            if ((i == n and j < n) or (j == n and i < n)) {
                return false;
            }
            if (s1[i] != s2[j] or (s1[i] == 'L' && i < j) or (s1[i] == 'R' and i > j)){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};