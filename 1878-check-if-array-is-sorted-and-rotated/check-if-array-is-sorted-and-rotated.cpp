class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int ind = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                cnt++;
            }
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1 or cnt <= 1 and nums[0] >= nums.back()){
            return true;
        }
        return false;
    }
};