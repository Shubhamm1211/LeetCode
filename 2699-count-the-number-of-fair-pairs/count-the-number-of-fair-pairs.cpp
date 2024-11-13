class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long int ans=0;
        int p=n-1;
        int d=n-1;
        int i=0;
        sort(nums.begin(),nums.end());
        while(i<d){
            long long int a=nums[i];
            while(p>0 && nums[p]>=(lower-a)){
                p--;
            }
            while(d>i && nums[d]>(upper-a)){
                d--;
            }
            if(d<=i){
                break;
            }
            ans=ans+(d-max(i,p));
            i++;
        }
        return ans;
    }
};