class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                char ch=s[i];
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    if(
                        (s[i]==')'&&st.top()=='(')||
                       (s[i]=='}'&&st.top()=='{')||
                       (s[i]==']'&&st.top()=='[') 
                    ){
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }
        if(!st.empty())return false;
        else return true;
    }
};