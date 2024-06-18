class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        for(int i=0;i<diff.size();i++){
            v.push_back({profit[i],diff[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int ans=0;
        for(int i=0;i<worker.size();i++){
            for(auto x:v){
                if(worker[i]>=x.second){
                ans=ans+x.first;
                break;
                }
            }
        }
        return ans;
    }
};