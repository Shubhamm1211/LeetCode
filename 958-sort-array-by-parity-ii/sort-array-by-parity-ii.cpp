class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
            ans[j]=nums[i];
            j=j+2;
            }
        }
        int k=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
            ans[k]=nums[i];
            k=k+2;
            }
        }
        return ans;
    }
};