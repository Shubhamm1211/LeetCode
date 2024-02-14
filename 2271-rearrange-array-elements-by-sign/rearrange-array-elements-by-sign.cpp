class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n); 
        int pi = 0;    
        int ni = 1;   
        
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                ans[pi] = v[i];
                pi =pi+ 2; 
            } else {
                ans[ni] = v[i];
                ni =ni+ 2;  
            }
        }
        
        return ans;
    }
};
