class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<=1000;i++){
            int cnt=0;
            for(auto e:nums){
                if(e>=i)cnt++;
            }
            if(cnt==i)ans=i;
        }
        return ans;
    }
};