class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack <char> st;
        st.push(s[0]);
        for(int i = 1 ; i < n ; i++){
            if((!st.empty()) and ((st.top() == 'A' and s[i] == 'B') or (st.top() == 'C' and s[i] == 'D'))){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};