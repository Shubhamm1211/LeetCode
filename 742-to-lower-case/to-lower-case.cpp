class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            ans.push_back(tolower(s[i]));
        }
        return ans;
    }
};