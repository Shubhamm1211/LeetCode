#include <string>

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int cnt = 0;
            int j = i;
            while (j < n && s[j] == c) {
                ++cnt;
                ++j;
            }
            result += string(min(2, cnt), c); 
            i = j - 1; 
        }
        return result;
    }
};
