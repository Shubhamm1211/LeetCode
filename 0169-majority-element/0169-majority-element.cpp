class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int elem;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                elem=nums[i];
                cnt++;
            }
            else if(elem==nums[i]){
                cnt++;
            }
            else cnt--;
        }
        return elem;
    }
};