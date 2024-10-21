class Solution {
public:
    int solve(string s, int ind, set <string> &ds){
        if(ind == s.size()){
            return 0;
        }
        int maxi = 0;
        for(int j = ind + 1; j <= s.size(); j++){
            string sub = s.substr(ind, j - ind);
            if(ds.count(sub) == 0){
                ds.insert(sub);
                maxi = max(maxi, 1 + solve(s,j,ds));
                ds.erase(sub);
            }
        }
        return maxi;
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        set <string> ds;
        string temp = "";
        return solve(s, 0, ds);
    }
};