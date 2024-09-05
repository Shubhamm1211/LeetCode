class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot=accumulate(rolls.begin(),rolls.end(),0);
        int m=rolls.size();
        int rem=(mean*(n+m))-tot;
        vector<int>ans;
        int t=rem/n;
        for(int i=0;i<n;i++){
        ans.push_back(t);
        }
        int mod=rem%n;
        for (int i=0;i<mod;i++) {
            ans[i]++;
        }
        for(int i=0;i<n;i++){
            if(ans[i]>6 || ans[i]<1)return{};
        }
        return ans;
    }
};