class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ptr = n - 1;
        set <int> st;
        st.insert(nums[ptr]);
        ptr--;
        int temp = 1;
        while(st.size() == temp and ptr >= 0){
            st.insert(nums[ptr]);
            ptr--;
            temp++;
        }
        int left = n - st.size() ;
        cout << left << endl;
        return ceil(left / 3.0);
    }
};