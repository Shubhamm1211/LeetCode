class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=0;
        int freq=0;
        long long count=0;
        
        while(j<n){
            if(nums[j]==maxi){ 
                freq++;
            }         
            while(freq==k){
                count=count+n-j;
                if(nums[i]==maxi){
                    freq--;
                }
                i++;
            }
            j++;
        }
        
        return count;
    }
};