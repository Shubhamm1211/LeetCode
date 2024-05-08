class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        vector<bool>ans;
        int n=c.size();
        int maxi=*max_element(c.begin(),c.end());
        for(int i=0;i<n;i++){
            if(c[i]+ec>=maxi)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};