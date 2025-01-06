class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector <int> res;
        for(int i = 0; i < n; i++){
            int ans = 0;
            for(int j = 0; j < n; j++){
                if(s[j] == '1') ans += abs(j - i);
            }
            res.push_back(ans);
        }
        return res;
    }
};