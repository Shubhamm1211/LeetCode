class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int s = 0;
        int e = size - 1;
        int mid = s + (e - s) / 2;
        int temp1 = -1; 
        int temp2 = -1; 
        vector<int> ret;

        while (s <= e) {
            if (nums[mid] == target) {
                temp1 = mid;
                e = mid - 1; 
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }


        s = 0;
        e = size - 1;
        mid = s + (e - s) / 2; 
        while (s <= e) {
            if (nums[mid] == target) {
                temp2 = mid;
                s = mid + 1; 
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }

        ret.push_back(temp1);
        ret.push_back(temp2);
        return ret;
    }
};
