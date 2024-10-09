class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;
        stack <char> st;
        for(auto c : s){
            if(c == '('){
                st.push(c);
            }
            else if(!st.empty() and c == ')' and st.top() == '('){
                st.pop();
            }
            else ans++;
        }
        ans += st.size();
        return ans;
    }
};