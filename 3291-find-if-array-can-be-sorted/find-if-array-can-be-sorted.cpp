class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
    
    bool canSortArray(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] > nums[i + 1]) cnt++;
        }
        
        for (int j = 0; j < size - 1; j++) {
            if (isSorted(nums)) return true;
            for (int i = 0; i < size - 1 - j; i++) {
                if (nums[i] > nums[i + 1]) {
                    if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i + 1])) {
                        swap(nums[i], nums[i + 1]);
                    }
                }
            }
        }
        
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        
        return true;
    }
};
