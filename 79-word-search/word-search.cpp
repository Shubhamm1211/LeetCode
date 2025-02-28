class Solution {
public:
    int n, m;
    bool find(int r, int c, int ind, vector <vector <char>> &v, string word){
        if(ind == word.size()){
            return true;
        }
        if(r < 0 or c < 0 or r >= n or c >= m) return false;
        if(v[r][c] == '#') return false;
        if(word[ind] != v[r][c]) return false;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        char temp = v[r][c];
        v[r][c] = '#';
        for(int i = 0; i < 4; i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if(find(nr, nc, ind + 1, v, word)){
                return true;
            }
        }
        v[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& v, string word) {
        n = v.size();
        m = v[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == word[0] and find(i,j,0,v,word)){
                    return true;
                }
            }
        }
        return false;
    }
};