class Solution {
public:
    void solve(int ind,int tar,vector<vector<int>>&ans,vector<int>&ds,vector<int>&can){
            if(tar==0){
                ans.push_back(ds);
                return;
            }
            for(int i=ind;i<can.size();i++){
                if(i>ind and can[i]==can[i-1])continue;
                if(can[i]>tar)break;
                ds.push_back(can[i]);
                solve(i+1,tar-can[i],ans,ds,can);
                ds.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(),can.end());
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,tar,ans,ds,can);
        return ans;
    }
};