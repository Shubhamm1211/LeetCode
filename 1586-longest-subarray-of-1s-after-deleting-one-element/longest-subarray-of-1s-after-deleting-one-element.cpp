class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        map <int,int> mp;
        int i = 0, j = 0;
        int maxf = 0, ans = 0, cnt1 = 0, cnt0 = 0;
        while(j < n){
            if(nums[j] == 0) cnt0++;
            else cnt1++;
            while(cnt0 > 1){
                if(nums[i] == 0){
                    cnt0-- ;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        // if(ans - 1 > cnt1) return cnt1;
        return ans - 1;
    }
};