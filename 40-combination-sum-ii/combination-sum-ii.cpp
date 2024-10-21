class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &v, int t, vector<int>&ds, int ind){
        if(t == 0){
            ans.push_back(ds);
            // return;
        }
        if(t < 0) return ;
        for(int j = ind; j < v.size(); j++){
            if (j > ind && v[j] == v[j - 1]) continue;
            ds.push_back(v[j]);
            solve(ans,v, t - v[j], ds, j + 1);
            ds.pop_back();
        } 
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector <int> ds;
        sort(begin(v),end(v));
        solve(ans,v,t,ds,0);
        return ans;
    }
};