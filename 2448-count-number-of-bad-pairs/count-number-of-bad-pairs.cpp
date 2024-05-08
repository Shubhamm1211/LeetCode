class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int res=0 ; 
       long long  int n=nums.size();
        unordered_map<int,int>m ; 
        long long int total=(n*(n-1))/2;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i; 
            res=res+m[nums[i]];
            m[nums[i]]++;
        }
        long long int ans=total-res;
        return ans;
        
        
        
    }
};