class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int r=image.size();
        int c=image[0].size();
         vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int i=0;i<r;i++){
            reverse(image[i].begin(),image[i].end());
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(image[i][j]==0){
                    image[i][j]=1;
                }
                else if(image[i][j]==1){
                    image[i][j]=0;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=image[i][j];
            }
        }
        return ans;
    }
};