class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto d:num){
            while(k>0 && !st.empty() && d<st.top()){
                st.pop();
                k--;
            }
            if(st.empty() && d=='0'){
                continue;
            }
            st.push(d);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return "0";
        else return ans;
    }
};