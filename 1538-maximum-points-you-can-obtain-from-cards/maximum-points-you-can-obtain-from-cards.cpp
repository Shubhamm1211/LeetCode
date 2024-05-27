class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int rsum=0,lsum=0,maxsum=0;
        for(int i=0;i<k;i++){
        lsum=lsum+nums[i];
        }
        maxsum=lsum;
        int ri=nums.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-nums[i];
            rsum=rsum+nums[ri];
            ri--;
            maxsum=max(maxsum,rsum+lsum);
        }
        return maxsum;
    }
};