#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && tolower(st.top()) == tolower(s[i]) && (isupper(st.top()) != isupper(s[i]))) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        if (st.empty()) return "";
        else {
            string ans = "";
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};
