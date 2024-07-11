class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string rev="";
                while(!st.empty() and st.top()!='('){
                    rev=rev+st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j=0;j<rev.size();j++){
                    st.push(rev[j]);
                }
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};