class Solution {
public:
    int calc(vector<int> nums, int tar){
        for(int i = 1; i <= 1000; i++){
            if((i | (i + 1)) == tar){
                return i;
            }
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        for(int i = 0; i < n; i++){
            int tar = nums[i];
            if(tar == 2){
                ans.push_back(-1);
            }
            else{
                ans.push_back(calc(nums,tar));
            }
        }
        return ans;
    }
};