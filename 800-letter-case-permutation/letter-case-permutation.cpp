class Solution {
public:
    vector <string> ans;
    bool is_digit(char c) {
        return (c >= '0' and c <= '9');
    }

    void solve(string op, string ip){
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        if(is_digit(ip[0])){
            op1 += ip[0];
            op2 += ip[0];
            ip.erase(ip.begin());
            solve(op1,ip);
            return;
        }
        op1 += toupper(ip[0]);
        op2 += tolower(ip[0]);
        ip.erase(begin(ip));
        solve(op1, ip);
        solve(op2, ip);
    }
    vector<string> letterCasePermutation(string s) {
        string ip = s;
        string op = "";
        solve(op,ip);
        return ans;
    }
};