#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);
        for(auto rd:roads){
            deg[rd[0]]++;
            deg[rd[1]]++;
        }
        ll ans=0;
        sort(deg.begin(),deg.end());
        for(ll i=1;i<=n;i++){
            ans=ans+deg[i-1]*i;
        }
        return ans;
    }
};