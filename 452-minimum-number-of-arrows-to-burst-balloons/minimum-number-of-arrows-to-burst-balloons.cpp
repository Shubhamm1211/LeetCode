class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n=points.size();

        int ans=1;

        int curr=points[0][1];

        for(int i=1;i<n;i++){
            if(points[i][0]>curr){
                curr=points[i][1];
                ans++;
            }
            else {
                curr=min(curr,points[i][1]);
            }
        }
        return ans;
    }
};