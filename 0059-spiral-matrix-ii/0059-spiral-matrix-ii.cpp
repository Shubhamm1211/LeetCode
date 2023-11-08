class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row=n;
        int col=n;

        int sr=0;
        int sc=0;
        int er=n-1;
        int ec=n-1;

        int total=n*n;
        int count=0;
        
        int fill=1;
        while(count<total){
            //generating first row
            for(int i=sc;i<=ec&&count<total;i++){
                ans[sr][i]=fill;
                fill++;
                count++;
            }
            sr++;

            //printing ending col
            for(int i=sr;i<=er&&count<total;i++){
                ans[i][ec]=fill;
                fill++;
                count++;
            }
            ec--;

            //printing ending row
            for(int i=ec;i>=sc&&count<total;i--){
                ans[er][i]=fill;
                fill++;
                count++;
            }
            er--;

            //printing staring col
            for(int i=er;i>=sr&&count<total;i--){
                ans[i][sc]=fill;
                fill++;
                count++;
            }
            sc++;

        }
        return ans;
    }
};