class Solution {
public:
    void solve(int open, int close, string s, vector <string> &ans){
        if(open == 0 and close == 0){
            ans.push_back(s);
            return;
        }
        if(open <= close and open > 0){
            solve(open - 1, close, s + '(', ans);
        }
        if(open < close){
            solve(open,close - 1, s + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string s = "";
        solve(n,n,s,ans);
        return ans;
    }
};