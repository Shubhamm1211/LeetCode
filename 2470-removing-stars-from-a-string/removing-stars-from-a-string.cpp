class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        st.push(s[0]);

        for(int i=1;i<s.size();i++){
            if(!st.empty() && s[i]=='*'){
                st.pop();
            }
            else st.push(s[i]);
            
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};