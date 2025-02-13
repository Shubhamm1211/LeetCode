class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        vector <string> v;
        int ptr = 1;
        int i = 1;
        // while(s[i] == '/') i++;
        while(i < n){
            if(s[i] == '/'){
                string temp = s.substr(ptr, i - ptr);
                v.push_back(temp);
                while(s[i] == '/'){
                    i++;
                }
                ptr = i;
            }
            else i++;
        }
        if(s.back() != '/'){
            string temp = s.substr(ptr, n - ptr);
            v.push_back(temp);
        }
        for(auto x : v) {
            if(x == "" or x == " ") cout << "e" << " ";
            else cout << x << " ";
        }
        stack <string> st;
        for(auto x : v){
            if(x == ".") continue;
            else if(x == " " or x == "") continue;
            else if(x == ".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(x);
            }
        }
        stack <string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        string ans = "/";
        while(st2.size() > 1){
            ans += st2.top() + '/';
            st2.pop();
        }
        if(st2.size() >= 1) ans += st2.top();
        return ans;
    }
};