class Solution {
public:
    int minOperations(vector<int>& nums) {
        set <int> st (nums.begin(),nums.end());
        vector <int> arr;
        for(auto x : st){
            arr.push_back(x);
        }
        int mini = nums.size();
        sort(begin(arr),end(arr));
        int n = nums.size();
        for(int i = 0; i < arr.size(); i++){
            int left = arr[i];
            int right = left + n - 1;
            int j = upper_bound(arr.begin(),arr.end(), right) - arr.begin();
            int valid = j - i;
            mini = min(mini, n - valid);
        }
        return mini;
    }
};
