class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>ex(h.begin(),h.end());
        int ans=0;
        sort(ex.begin(),ex.end());
        for(int i=0;i<ex.size();i++){
            if(h[i]!=ex[i])ans++;
        }
        return ans;
    }
};