class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int dist=0;
        for(int i=1;i<arrays.size();i++){
            vector<int>v=arrays[i];
            dist=max( dist,max ( abs(v.back()-mini), abs(maxi-v[0]) ) );
            mini=min(mini,v[0]);
            maxi=max(maxi,v.back());
        }
        return dist;
    }
};