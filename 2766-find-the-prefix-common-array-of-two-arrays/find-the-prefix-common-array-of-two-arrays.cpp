class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector <int> vis(n + 1,0);
        vector <int> ans(n,0);
        for(int i = 0; i < n; i++){
            vis[a[i]]++;
            vis[b[i]]++;
            for(int j = 0; j <= n; j++){
                if(vis[j] >= 2){
                    ans[i]++; 
                }
            }
        }
        return ans;
    }
};