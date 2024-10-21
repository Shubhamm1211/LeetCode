class Solution {
public:
    void solve(vector <int> &v, vector <vector<int>> &ans,int t, vector<int> &ds, int ind){
        if(t == 0){
            ans.push_back(ds);
            return;
        }
        if(t < 0) return;
        for(int j = ind; j < v.size(); j++){
            ds.push_back(v[j]);
            solve(v,ans,t - v[j], ds, j);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector <vector<int>> ans;
        vector <int> ds;
        solve(v,ans,t,ds,0);
        return ans;
    }
};