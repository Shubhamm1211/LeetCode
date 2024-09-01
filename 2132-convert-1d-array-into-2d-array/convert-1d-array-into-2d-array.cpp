class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int org=original.size();
        vector<vector<int>>ans(m,vector<int>(n));
        if(m*n!=org)return {};
        else{
            int ptr=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ans[i][j]=original[ptr];
                    ptr++;
                }
            }
            return ans;
        }
    }
};