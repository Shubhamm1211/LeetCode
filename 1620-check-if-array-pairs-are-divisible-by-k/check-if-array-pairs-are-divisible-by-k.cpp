class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> freq(k);
        for(int i = 0; i < n; i++){
            int rem = ((arr[i] % k) + k) % k;
            freq[rem]++;
        }
        if(freq[0] % 2 != 0)return false;
        for(int i = 1; i <= k/2; i++){
            if(freq[i] != freq[k - i]){
                return false;
            }
        }
        return true;
    }
};