class Solution {
public:
    int trap(vector<int> &h) {
        int n = h.size();
        vector <int> maxr(n), maxl(n);
        maxr[n - 1] = h[n - 1];
        for(int i = n - 2; i >= 0; i--){
            maxr[i] = max(maxr[i + 1], h[i]);
        }
        maxl[0] = h[0];
        for(int i = 1; i < n; i++){
            maxl[i] = max(maxl[i - 1], h[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(maxr[i],maxl[i]) - h[i];
        }
        return ans;
    }
};