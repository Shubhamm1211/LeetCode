class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX;
        int j=INT_MAX;
        for(auto &it:nums){
            if(it<=i){
                i=it;
            }
            else if(it<=j){
                j=it;
            }
            else return true;
        }
        return false;
    }
};