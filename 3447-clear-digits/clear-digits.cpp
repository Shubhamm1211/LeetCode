class Solution {
public:
    string clearDigits(string s) {
        stack <int> st;
        for(int i = 0; i < s.size(); i++){
            if('0' <= s[i] and s[i] <= '9'){
                st.push(i);
            }
        }
        while(!st.empty()){
            int tar = st.top();
            st.pop();
            s[tar] = '#';
            tar--;
            while(tar >= 0){
                if('a' <= s[tar] and s[tar] <= 'z'){
                    s[tar] = '#';
                    break;
                }
                tar--;
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                ans += s[i];
            }
        }
        return ans;
    }
};