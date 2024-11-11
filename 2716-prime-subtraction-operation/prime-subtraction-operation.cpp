class Solution {
public:
    bool check(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp;
            if (i == 0) {
                temp = nums[0];
            }
            else {
                temp = nums[i] - nums[i - 1];
            }
            if (temp <= 0) {
                return 0;
            }
            int maxi = 0;
            for (int j = temp - 1; j >= 2; j--) {
                if (check(j)) {
                    maxi = j;
                    break;
                }
            }
            nums[i] = nums[i] - maxi;
        }
        return 1;
    }
};