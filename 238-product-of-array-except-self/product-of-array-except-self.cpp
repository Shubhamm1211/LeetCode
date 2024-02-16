class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int pro=1;
        for(auto it:nums){
            if(it==0)cnt0++;
            else{
                pro=pro*it;
            }
        }
        if(cnt0>=2){
            vector<int>ans(n,0);
            return ans;
        }
        if(cnt0==1){
            vector<int>ans(n,0);
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=pro;
                }
            }
            return ans;
        }
        else{
            vector<int>ans;
            for(int i=0;i<n;i++){
                ans.push_back(pro/nums[i]);
            }
            return ans;
        }
    }
};