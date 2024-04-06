class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1=nums.back();
        int max2=INT_MIN;
        int max3=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<max1){
            max2=nums[i];
            break;
            }
        }
        bool flag=false;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<max2){
            max3=nums[i];
            flag=true;
            break;
            }
        }
        if(flag==false)return max1;
        else return max3;
    }
};