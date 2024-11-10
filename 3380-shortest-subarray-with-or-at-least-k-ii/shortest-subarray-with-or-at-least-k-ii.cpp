class Solution {
public:
    void update(vector <int> &bits, int num, int temp){
        for(int i = 0; i < 32; i++){
            if(((num >> i) & 1) == 1){
                bits[i] += temp;
            }
        }
    }
    int convert(vector <int> &bits){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i]){
                ans |= (1 << i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        vector <int> bits(32,0);
        int mini = INT_MAX;
        while(j < n){
            update(bits,nums[j],1);
            while(i <= j and convert(bits) >= k){
                mini = min(mini, j - i + 1);
                update(bits,nums[i],-1);
                i++;
            }
            j++;
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};