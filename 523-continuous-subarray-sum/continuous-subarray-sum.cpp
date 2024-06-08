class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int v=sum%k;
            if(mp.find(v)!=mp.end()){
                if(i-mp[v]>=2){
                    return true;
                }
            }
            else mp[v]=i;
        }
        
        
        return false;
    }
};