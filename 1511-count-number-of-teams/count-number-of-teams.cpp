class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans=0;
        int n=r.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<j;k++){
                    if((r[i]<r[j] and r[j]<r[k]) || (r[i]>r[j] and r[j]>r[k]))ans++;
                }
            }
        }
        return ans;
    }
};