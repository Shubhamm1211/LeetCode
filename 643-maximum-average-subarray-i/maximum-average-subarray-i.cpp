class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] = nums[i - 1] + nums[i];
        }
        double maxi = nums[k - 1] / (k * 1.0);
        for(int i = k; i < n; i++){
            int sum = nums[i] - nums[i - k];
            double avg = sum / (k * 1.0);
            maxi = max(maxi,avg); 
        }
        return maxi;
    }
};