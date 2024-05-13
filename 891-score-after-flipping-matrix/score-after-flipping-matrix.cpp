class Solution {
public:
    void flip(vector<int>&v){
        for(int i=0;i<v.size();i++){
            if(v[i]==1)v[i]=0;
            else v[i]=1;
        }
    }
    int num(vector<int>v) {
    int ans=0;
    int power=1; 

    for (int i=v.size()-1;i>=0;i--) {
        ans+=v[i]*power;
        power*=2;
    }
    return ans;
}
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                flip(grid[i]);
            }
        }
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0)cnt++;
            }
            if(cnt>n/2){
                for(int k=0;k<n;k++){
                    if(grid[k][i]==1)grid[k][i]=0;
                    else grid[k][i]=1;
                }
            }
        }
        for(auto v:grid){
            for(auto nn:v){
                cout<<nn<<" ";
            }
            cout<<endl;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=res+num(grid[i]);
        }
        return res;

    }
};