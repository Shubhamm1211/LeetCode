class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        map<int,int>mp1,mp2;
        for(auto e:nums){
            mp1[e]++;
        }
        int uq=mp1.size();
        int l=0,r=0,ans=0;
        int n=nums.size();
        while(r<n){
            mp2[nums[r]]++;
                while(mp2.size()==uq){
                    ans=ans+(n-r);
                    mp2[nums[l]]--;
                    if(mp2[nums[l]]==0)mp2.erase(nums[l]);
                    l++;
                }
            
            r++;
        }
        return ans;
    }
};