class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector <vector<int>> mat(n,vector<int>(n,1e9));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) mat[i][j] = 0;
            }
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][k] != 1e9 and mat[k][j] != 1e9 and mat[i][k] + mat[k][j] < mat[i][j]){
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }
        int ind = -1;
        int maxi = n;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] != 1e9 and mat[i][j] <= dist){
                    temp++;
                }
            }
            if(temp <= maxi){
                maxi = temp;
                ind = i;
            }
        }
        return ind;
    }
};