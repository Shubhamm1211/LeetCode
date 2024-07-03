class Solution {
public:
    bool check(int mid,int p,vector<int>&nums){
        int f=0,cnt=0;
        
        for(int i=1;i<nums.size();i++){
            if(f){
            f=0;
            continue;
        }
        if(nums[i]-nums[i-1]<=mid){
            f=1;
            cnt++;
        }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,ans=-1;
        int high=nums[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,p,nums)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};