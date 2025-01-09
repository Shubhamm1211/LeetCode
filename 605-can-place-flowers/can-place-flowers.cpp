class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int tot) {
        int n = nums.size();
        if(n == 1){
            int cnt = 0;
            if(nums[0] == 0) cnt++;
            return cnt >= tot;
        }
        int c1 = 0, c0 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) c0++;
            else c1++;
        }
        if(c1 == n){
            return tot == 0;
        }
        if(c0 == n){
            return tot <= (n + 1) / 2;
        }
        int fi = -1;
        if(nums[0] == 0 and nums[1] == 0) {
            fi = 0;
            nums[0] = 1; 
        }
        else{
            for(int i = 1; i < n - 1; i++){
                if(nums[i] == 0 && nums[i - 1] == 0 && nums[i + 1] == 0){
                    fi = i;
                    nums[i] = 1; 
                    break;
                }
            }
        }
        if(fi == -1){
            if(nums[n - 2] == 0 && nums[n - 1] == 0){
                fi = n - 1;
                nums[n-1] = 1;
            }
        }
        if(fi == -1){
            return tot == 0;
        }
        int cnt = 1;
        for(int i = fi + 2; i < n - 1; i++){  
            if(nums[i - 1] == 0 and nums[i] == 0 and nums[i + 1] == 0){
                cnt++;
                nums[i] = 1; 
                i++;  
            }
        }
        if(nums[n - 2] == 0 and nums[n - 1] == 0) {
            cnt++;
        }
        return cnt >= tot;
    }
};