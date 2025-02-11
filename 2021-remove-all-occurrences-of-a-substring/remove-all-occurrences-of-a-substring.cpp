class Solution {
public:
    string removeOccurrences(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        stack <char> st;
        for(int i = 0; i < n1; i++){
            if(s[i] == p.back()){
                int temp = n2 - 1;
                string bud = "";
                while(!st.empty() and temp){
                    bud = st.top() + bud;
                    st.pop();
                    temp--;
                }
                bud = bud + s[i];
                cout << bud << endl;
                if(bud != p){
                    for(auto &x : bud){
                        st.push(x);
                    }
                }
            }
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};