class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int> bits(32);  
        for(auto x : nums){
            for(int i = 0; i < 31; i++){
                if(x & (1 << i)){
                    bits[i]++;
                }
            }
        }
        int ans = *max_element(begin(bits), end(bits));
        return ans;
    }
};
