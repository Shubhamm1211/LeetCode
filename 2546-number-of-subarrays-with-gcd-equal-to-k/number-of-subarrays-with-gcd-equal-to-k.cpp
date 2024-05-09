class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=i;j<n;j++){
                t=gcd(t,nums[j]);
                if(t==k)ans++;
            }
        }
        return ans;
    }
};