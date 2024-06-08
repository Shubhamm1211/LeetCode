class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size(),maxi=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum=sum-x;
        if(sum==0)return n;
        int s=0,e=0,currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            while(s<n && currsum>sum){
                currsum-=nums[s];
                s++;
            }
            if(sum==currsum)maxi=max(maxi,i-s+1);
        }
        if(maxi==0)return -1;
        return n-maxi;
    }
};