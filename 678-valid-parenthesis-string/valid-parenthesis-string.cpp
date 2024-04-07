class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lefts, stars;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') lefts.push(i);
            else if (s[i] == '*') stars.push(i);
            else {
                if (!lefts.empty()) lefts.pop();
                else if (!stars.empty()) stars.pop();
                else return false;
            }
        }
        while (!lefts.empty() && !stars.empty()) {
            if (lefts.top() > stars.top()) return false;
            lefts.pop();
            stars.pop();
        }
        return lefts.empty();
    }
};


