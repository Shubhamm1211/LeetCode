class Solution {
public:
    int rev(int n){
        int temp=0;
        while(n>0){
            temp=(temp*10 + n%10);
            n=n/10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(n--){
            nums.push_back(rev(nums[i]));
            i++;
        }
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        return st.size();
    }
};