class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& v) {
        vector <int> vis(s.size(), 0);
        for(int i = 0; i < v.size(); i++){
            int start = v[i][0];
            int end = v[i][1];
            int dir = v[i][2];
            vis[start] += dir ? 1 : -1;
            if (end + 1 < s.size()) vis[end + 1] -= dir ? 1 : -1;
        }
        for(int i = 1; i < s.size(); i++){
            vis[i] = vis[i - 1] + vis[i];
        }
        for(int i = 0; i < s.size(); i++){
            int as = s[i] - 'a' + vis[i];

            s[i] = char((as % 26 + 26) % 26 + 'a');
            // cout << (as % 26 + 26) % 26 << " ";
        }
        return s;
    }
};