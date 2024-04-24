class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        sort(p.begin(),p.end());
        int ans=1;
        int agla=w+p[0][0];
        for(int i=0;i<p.size();i++){
            if(p[i][0]>agla){
                ans++;
                agla=w+p[i][0];
            }
        }
        return ans;
    }
};