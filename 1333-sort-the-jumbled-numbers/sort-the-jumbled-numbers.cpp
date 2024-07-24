bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
    if(a.first==b.first)return a.second.second<b.second.second;
    return a.first<b.first;
}
class Solution {
public:
    int solve(int num,vector<int>mapping){
        if (num==0)return mapping[0];
        int mapped=0;
        int multiplier=1;
        while (num>0) {
            int dig=num%10;
            mapped=mapping[dig]*multiplier+mapped;
            num=num/10;
            multiplier*=10;
        }
        return mapped;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n=nums.size();
    vector<pair<int,pair<int,int>>>v;//{{mappedVal,{org,i}}}
    for(int i=0;i<n;i++){
        int mappedVal=solve(nums[i],mapping);
        v.push_back({mappedVal,{nums[i],i}});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(v[i].second.first);
    }
    return ans;
    }
};

