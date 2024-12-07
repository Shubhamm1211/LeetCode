class Solution {
public:
bool solve(int ball, vector<int>& nums, int maxi) {
        int tot = 0;
        for (int num : nums) {
            int op = ceil(num / (double)ball) - 1;
            tot += op;
            if (tot > maxi) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxi) {
        int left = 1;
        int right = 0;

        for (auto num : nums) {
            right = max(right, num);
        }
        while (left < right) {
            int middle = (left + right) / 2;
            if (solve(middle, nums, maxi)) {
                right = middle;           
            } 
            else {
                left = middle + 1;             
            }
        }
        return left;
    }
};