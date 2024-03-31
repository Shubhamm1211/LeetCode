class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        

        long long ans = 0;

        
        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;

        int i = 0;
        while(i < nums.size()) {
            
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;
            
            int count = min(maxPosition, minPosition) - leftBound;
            
            ans += (count <= 0) ? 0 : count;

            i++;
        }
        return ans;
    }
};