class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int  n = nums.size();
        sort(nums.begin() , nums.end());
        int min = -1;
        if(nums[0] == 0){
            min = 0;
        }
       else{
           min = 1;
       }

        for(int i = 0 ; i < n ; i++){
            if(min == nums[i]){
               min =  min+1;
            }
           
        }
        return min ;
    }
};