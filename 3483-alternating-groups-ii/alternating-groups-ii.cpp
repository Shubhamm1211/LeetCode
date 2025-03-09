class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int i = 0, j = 1;
        for(int g = 0; g < k - 1; g++){
            nums.push_back(nums[g]);
        }
        int n = nums.size();
        int ans = 0;
        while(i <= j and j < n){
            if(nums[j] == nums[j - 1]){
                i = j;
            }
            else{
                if(j - i + 1 == k){
                    ans++;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};