class Solution {
public:
    void solve(vector <string> &ans, string temp, int open, int close){
        if(open == 0 and close == 0){
            ans.push_back(temp);
            return;
        }
        if(open > 0){
            solve(ans,temp + '(', open - 1, close);
        }
        if(close > open){
            solve(ans, temp + ')', open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string temp = "";
        int open = n; 
        int close = n;
        solve(ans,temp,open,close);
        return ans;
    }
};