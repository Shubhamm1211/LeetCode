class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDiff, int valueDiff) {
        int minIdx = 0, maxIdx = 0, n = nums.size();
      
        for (int i = indexDiff; i < n; i++) {
            if (nums[i - indexDiff] < nums[minIdx]) 
            minIdx = i - indexDiff;
           
            if (nums[i] - nums[minIdx] >= valueDiff) 
            return {i, minIdx};

            if (nums[i - indexDiff] > nums[maxIdx]) 
            maxIdx = i - indexDiff;
            
            if (nums[maxIdx] - nums[i] >= valueDiff) 
            return {i, maxIdx};
        }
        
        return { -1, -1};
    }
};
