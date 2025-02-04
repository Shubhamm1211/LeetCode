class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int time) {
        int n = v.size();
        vector <int> pre(n,0),suff(n,0);
        for(int i = 1; i < n; i++){
            if(v[i - 1] >= v[i]){
                pre[i] += pre[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(v[i] <= v[i + 1]){
                suff[i] += suff[i + 1] + 1;
            }
        }
        vector <int> ans;
        for(int i = 0; i < n; i++){
            if(pre[i] >= time and suff[i] >= time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};