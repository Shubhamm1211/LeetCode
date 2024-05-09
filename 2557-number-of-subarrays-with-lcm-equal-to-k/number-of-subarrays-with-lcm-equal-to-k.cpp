class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t=1;
            for(int j=i;j<n;j++){
                t=lcm(t,nums[j]);
                if(t>k)break;
                if(t==k)ans++;
                
            }
        }
        return ans;
    }
};