class Solution {
public:
    void solve(int ind,vector<int>&c,int t,vector<int>&v,vector<vector<int>>&ans){
        if(ind==c.size()){
            if(t==0){
                ans.push_back(v);
            }
            return;
        }
        if(c[ind]<=t){
            v.push_back(c[ind]);
            solve(ind,c,t-c[ind],v,ans);
            v.pop_back();
        }
        solve(ind+1,c,t,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(0,c,t,v,ans);
        return ans;
    }
};
