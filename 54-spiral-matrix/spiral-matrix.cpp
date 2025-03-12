class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <int> ans;
        int sr = 0, er = n - 1, sc = 0, ec = m - 1;
        int tot = n * m, cnt = 0;
        while(cnt < tot){
            for(int i = sc; i <= ec and cnt < tot; i++){
                ans.push_back(mat[sr][i]);
                cnt++;
            }
            sr++;
            for(int i = sr; i <= er and cnt < tot; i++){
                ans.push_back(mat[i][ec]);
                cnt++;
            }
            ec--;
            for(int i = ec; i >= sc and cnt < tot; i--){
                ans.push_back(mat[er][i]);
                cnt++;
            }
            er--;
            for(int i = er; i >= sr and cnt < tot; i--){
                ans.push_back(mat[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans; 
    }
};